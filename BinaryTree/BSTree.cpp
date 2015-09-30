#include"BSTree.h"

void BinarySearchTree::deleteValue(TreeNode *node,int value){
  static bool left=true;

  TreeNode *parentNode=NULL,*curNode=node;
  std::list<TreeNode*> leftSizeList;
  while(curNode){
       if (curNode->value==value){
         break;
       }
       else if (curNode->value > value){
         leftSizeList.push_back(curNode);
         parentNode=curNode; 
         curNode=curNode->leftNode;
       }
       else{
         parentNode=curNode;
         curNode=curNode->rightNode;
       }
  }
  if(!curNode) return;
  
  while (!leftSizeList.empty()){
       TreeNode *tempNode=leftSizeList.front();
       leftSizeList.erase(leftSizeList.begin());
       tempNode->leftSize--;
  }

  if (!curNode->leftNode && !curNode->rightNode){
    if (parentNode->rightNode==curNode){
      parentNode->rightNode=NULL;
      delete curNode;
      curNode=NULL;
    }
    else{
      parentNode->leftNode=NULL;
      delete curNode;
      curNode=NULL;
    } 
  }
  else if (!curNode->leftNode && curNode->rightNode){
    if (parentNode->rightNode==curNode){
      parentNode->rightNode=curNode->rightNode;
      delete curNode;
      curNode=NULL; 
    } 
    else{
      parentNode->leftNode=curNode->rightNode;
      delete curNode;
      curNode=NULL;
    }  
  }  
  else if (curNode->leftNode && !curNode->rightNode){
    if (parentNode->rightNode==curNode){
      parentNode->rightNode=curNode->leftNode;
      delete curNode;
      curNode=NULL;
    }
    else{
      parentNode->leftNode=curNode->leftNode;
      delete curNode;
      curNode=NULL;
    }
  }
  else{
    if (left){
      left=false;
      TreeNode *newRoot=curNode;
      curNode=curNode->leftNode;
      while (curNode->rightNode){
           curNode=curNode->rightNode;
      }
      newRoot->value=curNode->value+1;
      deleteValue(newRoot,curNode->value);  
      newRoot->value=newRoot->value-1;  
    }    
    else{
      left=true;
      TreeNode *newRoot=curNode;
      curNode=curNode->rightNode;
      while (curNode->leftNode){
           curNode=curNode->leftNode;
      }
      newRoot->value=curNode->value-1;
      deleteValue(newRoot,curNode->value);
      newRoot->value=newRoot->value+1;
    }
  }
}

TreeNode* BinarySearchTree::searchRank(int rank){
  TreeNode *node=root;
  while (node){
       if (node->leftSize==rank){
         return node;
       }
       else if(node->leftSize > rank){
         node=node->leftNode;
       }
       else{
           rank=rank-node->leftSize;
           node=node->rightNode;
       }
  }
  return NULL;
}



void BinarySearchTree::insert(int value){
  if (!root){
    root=new TreeNode(value);
  }
  else{
    insert(root,value);
  }
  treeSize++;
}

void BinarySearchTree::insert(TreeNode* node, int value){
    if (value == node->value){
      std::cout<<"duplicate key"<<std::endl;
      treeSize--;
      return;
    } 
    else if (value > node->value ){
      if (node->rightNode){
        insert(node->rightNode,value);
      }
      else{
        node->rightNode=new TreeNode(value);      
      }
    }
    else{
      node->leftSize++;
      if (node->leftNode){
        insert(node->leftNode,value);
      }
      else{
        node->leftNode=new TreeNode(value);
      }
    }  
}

bool BinarySearchTree::search(int value){
  TreeNode *curNode=root;
  while(curNode){
       if(curNode->value==value) return true;
       else if(curNode->value > value) curNode=curNode->leftNode;
       else curNode=curNode->rightNode;
  }
  return false;
}


void BinarySearchTree::deleteTree(TreeNode** currentNode)
{
  if(*currentNode){
    deleteTree(&((*currentNode)->leftNode));
    deleteTree(&((*currentNode)->rightNode));
    // When delete pointer, the value of the pointer is non-defined
    // Hence, we set the pointer to NULL after pointer deletion.
    // Notice that we must use double point here  
    delete *currentNode; 
    *currentNode=NULL; 
  } 
}

void BinarySearchTree::preorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    std::cout<<currentNode->value<<" ";
    preorderVec.push_back(currentNode->value);
    preorder(currentNode->leftNode);
    preorder(currentNode->rightNode);
  }
}



void BinarySearchTree::inorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    inorder(currentNode->leftNode);
    std::cout<<currentNode->value<<" ";
    inorderVec.push_back(currentNode->value);
    inorder(currentNode->rightNode);
  }
}


void BinarySearchTree::postorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    postorder(currentNode->leftNode);
    postorder(currentNode->rightNode);
    std::cout<<currentNode->value<<" ";
    //postorderVec.push_back(currentNode->value);
  }
}


void BinarySearchTree::levelOrder()
{
  std::queue<TreeNode*> nodeQueue;
  TreeNode *currentNode=root;
  if(!root) return;
  nodeQueue.push(root); 
  do{
    currentNode=nodeQueue.front();
    nodeQueue.pop();
    std::cout<<currentNode->value<<" "; 
    if(currentNode->leftNode) nodeQueue.push(currentNode->leftNode);
    if(currentNode->rightNode) nodeQueue.push(currentNode->rightNode); 
  }while(!nodeQueue.empty());
  std::cout<<std::endl;
}

void BinarySearchTree::levelOrderLeftSize()
{
  std::queue<TreeNode*> nodeQueue;
  TreeNode *currentNode=root;
  if(!root) return;
  nodeQueue.push(root);
  do{
    currentNode=nodeQueue.front();
    nodeQueue.pop();
    std::cout<<currentNode->leftSize<<" ";
    if(currentNode->leftNode) nodeQueue.push(currentNode->leftNode);
    if(currentNode->rightNode) nodeQueue.push(currentNode->rightNode);
  }while(!nodeQueue.empty());
  std::cout<<std::endl;
}

int main()
{
  BinarySearchTree a;
  a.insert(10);  
  a.insert(15);
  a.insert(2);
  a.insert(4);
  a.insert(13);
  a.insert(20);
  a.insert(12);
  a.insert(14);
  a.insert(19);
  a.insert(21);  

  a.levelOrder();
  a.check();
  //std::cout<<a.treeSize<<std::endl;
  a.deleteValue(15); 
  a.levelOrder();
  a.check();
  //std::cout<<a.treeSize<<std::endl;
  a.deleteValue(10);
  a.levelOrder();
  a.check();
  a.deleteValue(2);
  a.levelOrder();
  a.check();
  a.deleteValue(4);
  a.levelOrder();
  a.check();
  return 0;
} 
