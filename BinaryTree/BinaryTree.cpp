#include"BinaryTree.h"


template<typename T>
BinaryTree<T>::BinaryTree()
{
  std::queue<TreeNode<T>*> nodeQueue;
  TreeNode<T> *currentNode=NULL;
  
  root=new TreeNode<T>(1);
  nodeQueue.push(root);
  
  for(int i=1;i<8;i++){
      currentNode=nodeQueue.front();
      nodeQueue.pop();
      currentNode -> leftNode = new TreeNode<T>(2*i);
      nodeQueue.push(currentNode -> leftNode );
      currentNode -> rightNode = new TreeNode<T>(2*i+1);
      nodeQueue.push(currentNode -> rightNode );
  }
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> & copyTree)
{
  deleteTree();
  root=copy(copyTree.root);
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T> &assignTree)
{
  if(this!=&assignTree){
    deleteTree();
    root=copy(assignTree.root);
  }
  return *this;
}

template<typename T>
TreeNode<T>* BinaryTree<T>::copy(const TreeNode<T> * origNode)
{
  if(!origNode) return NULL;
  TreeNode<T> *currentNode=new TreeNode<T>(origNode->value);
  if(origNode->leftNode) currentNode->leftNode=copy(origNode->leftNode);
  if(origNode->rightNode) currentNode->rightNode=copy(origNode->rightNode);
  return currentNode;
}

template<typename T>
bool BinaryTree<T>::equal(const TreeNode<T> *thisNode,  const TreeNode<T> *compareNode)
{
  if(!thisNode && !compareNode) return true;
  if(thisNode && compareNode && thisNode->value==compareNode->value && equal(thisNode->leftNode,compareNode->leftNode) &&equal(thisNode->rightNode,compareNode->rightNode))
    return true;
  return false;  
}

template<typename T>
void BinaryTree<T>::deleteTree(TreeNode<T>** currentNode)
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

template<typename T>
void BinaryTree<T>::preorder(TreeNode<T> * currentNode)
{
  if(currentNode!=NULL){
    std::cout<<currentNode->value<<" ";
    preorderVec.push_back(currentNode->value);
    preorder(currentNode->leftNode);
    preorder(currentNode->rightNode);
  }
}


template<typename T>
void BinaryTree<T>::inorder(TreeNode<T> * currentNode)
{
  if(currentNode!=NULL){
    inorder(currentNode->leftNode);
    std::cout<<currentNode->value<<" ";
    inorderVec.push_back(currentNode->value);
    inorder(currentNode->rightNode);
  }
}


template<typename T>
void BinaryTree<T>::postorder(TreeNode<T> * currentNode)
{
  if(currentNode!=NULL){
    postorder(currentNode->leftNode);
    postorder(currentNode->rightNode);
    std::cout<<currentNode->value<<" ";
    //postorderVec.push_back(currentNode->value);
  }
}


template<typename T>
void BinaryTree<T>::preorderStack()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;
 
  while(1){
        // keep doing prorder with new root=leftNode
     	while(currentNode){
              std::cout<<currentNode->value<<" ";
              nodeStack.push(currentNode);
              currentNode=currentNode->leftNode;
        }
        
        // If rightNode is NULL, the previous while test fails. 
        // nodeStack keep popping until rightNode isn't NULL
        // Then, use newroot=rightNode to do preorder again      
        if(!nodeStack.empty()){
              currentNode = nodeStack.top();
              nodeStack.pop();
              currentNode=currentNode->rightNode;
        }
        else
           break;
  }
}

template<typename T>
void BinaryTree<T>::preorderStack2()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;

  do{
        while(currentNode){
              std::cout<<currentNode->value<<" ";
              nodeStack.push(currentNode);
              currentNode=currentNode->leftNode;
        }
       
        // Poppin stack until rightNode isn't NULL. 
        // It means we get nonNULL rightNode in this while loop without using
        // on previous while test. (method 1 would use the previous while test)
        // Then, use root=rightNode to do preorder again
        while(!nodeStack.empty() && !currentNode){
              currentNode = nodeStack.top();
              nodeStack.pop();
              currentNode=currentNode->rightNode;
        }
  }while(!nodeStack.empty() || currentNode);

}

template<typename T>
void BinaryTree<T>::preorderStack3()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;
  if(!root) return;
  nodeStack.push(root);
  do{
        currentNode=nodeStack.top();
        nodeStack.pop();
        std::cout<<currentNode->value<<" ";
        if(currentNode->rightNode){
              nodeStack.push(currentNode->rightNode);
        }

        if(currentNode->leftNode){
              nodeStack.push(currentNode->leftNode);
        }
  }while(!nodeStack.empty());

}

template<typename T>
void BinaryTree<T>::inorderStack()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;

  while(1){
        while(currentNode){
              nodeStack.push(currentNode);
              currentNode=currentNode->leftNode;
        }
        // First top/pop is leftNode, and second top/pop is its parent.  
        // Then if rightNode is NULL, their parents are kept top/pop
        // If rightNode isn't NULL, do inorder with root=rightNode again  
        if(!nodeStack.empty()){
              currentNode = nodeStack.top();
              nodeStack.pop();
              std::cout<<currentNode->value<<" ";
              currentNode=currentNode->rightNode;
        }
        else
           break;
  }

}


/*
inverser postorder 
LRV = inverse (VRL) that similar to preorder 
*/
template<typename T>
void BinaryTree<T>::postorderStack()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;
  if(!root) return;
  nodeStack.push(root);
  do{
        currentNode=nodeStack.top();
        nodeStack.pop();

        postorderVec.push_back(currentNode->value);
        if(currentNode->leftNode){
              nodeStack.push(currentNode->leftNode);
        }

        if(currentNode->rightNode){
              nodeStack.push(currentNode->rightNode);
        }
  }while(!nodeStack.empty());
  
  //cost is high
  reverse(postorderVec.begin(),postorderVec.end());

  for(int i=0;i<postorderVec.size();i++)
      std::cout<<postorderVec.at(i)<< " ";
}

template<typename T>
void BinaryTree<T>::postorderStack2()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *preNode=root,*currentNode=root;
  if(!root) return;
  nodeStack.push(root);
  do{
        currentNode=nodeStack.top();
        // 1. node is leaf 2./3. node is parent and children are popped already
        // Then, it means leftNode and rightNode are popped already 
        // Hence, we can pop their parent
        if( (!currentNode->leftNode && !currentNode->rightNode) || currentNode->leftNode==preNode || currentNode->rightNode==preNode){
            std::cout<<currentNode->value<<" ";
            nodeStack.pop();  
            preNode=currentNode;
        }        
        else{
           if(currentNode->rightNode) nodeStack.push(currentNode->rightNode);
           if(currentNode->leftNode) nodeStack.push(currentNode->leftNode);
        }
  }while(!nodeStack.empty());

}

/*
use flag
*/
template<typename T>
void BinaryTree<T>::postorderStack3()
{
  std::stack<TreeNode<T>*> nodeStack;
  TreeNode<T> *currentNode=root;
  bool leftFlag=false, rightFlag=false;
  if(!root) return;
  nodeStack.push(root);
  do{
     currentNode=nodeStack.top();
     while(!leftFlag && currentNode->leftNode){
       nodeStack.push(currentNode->leftNode);
       currentNode=currentNode->leftNode;
     }
     
     if(!rightFlag &&  currentNode->rightNode){
       nodeStack.push(currentNode->rightNode);
       leftFlag=false;
     }
     else{
       std::cout<<currentNode->value<<" ";
       nodeStack.pop();
       leftFlag=true;
       if(!nodeStack.empty() && nodeStack.top()->rightNode==currentNode)
          rightFlag=true;
       else
          rightFlag=false;
     }

  }while(!nodeStack.empty());
}

template<typename T>
void BinaryTree<T>::levelorderQueue()
{
  std::queue<TreeNode<T>*> nodeQueue;
  TreeNode<T> *currentNode=root;
  if(!root) return;
  nodeQueue.push(root); 
  do{
    currentNode=nodeQueue.front();
    nodeQueue.pop();
    std::cout<<currentNode->value<<" "; 
    if(currentNode->leftNode) nodeQueue.push(currentNode->leftNode);
    if(currentNode->rightNode) nodeQueue.push(currentNode->rightNode); 
  }while(!nodeQueue.empty());
}

int main()
{
  BinaryTree<int> testTree;
  
  std::cout<<"preorder:"<<std::endl;
  testTree.preorder();
  std::cout<<std::endl;
  testTree.preorderStack();
  std::cout<<std::endl;
  testTree.preorderStack2();
  std::cout<<std::endl;
  testTree.preorderStack3();
  std::cout<<std::endl;
  
  std::cout<<"inorder:"<<std::endl;
  testTree.inorder();
  std::cout<<std::endl;
  testTree.inorderStack();
  std::cout<<std::endl;

  std::cout<<"postorder:"<<std::endl;
  testTree.postorder();
  std::cout<<std::endl;
  testTree.postorderStack();
  std::cout<<std::endl;
  testTree.postorderStack2();
  std::cout<<std::endl;
  testTree.postorderStack3();
  std::cout<<std::endl;

  std::cout<<"levelorder:"<<std::endl;
  testTree.levelorderQueue();
  std::cout<<std::endl;
  
  BinaryTree<int> testTree2(testTree);
  
  testTree2=testTree2;
  testTree2.levelorderQueue();
  return 0;
}
