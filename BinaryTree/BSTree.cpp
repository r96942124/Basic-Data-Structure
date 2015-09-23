#include"BinaryTree.h"


bool search(int value){
  TreeNode *curNode=root;
  while(curNode){
       if(curNode->value==value) return true;
       else if(curNode->value > value) curNode=curNode->leftNode;
       else curNode=curNode->rightNode;
  }
  return false;
}

BinaryTree::BinaryTree(const BinaryTree  &copyTree)
{
  deleteTree();
  root=copy(copyTree.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree &assignTree)
{
  if(this!=&assignTree){
    deleteTree();
    root=copy(assignTree.root);
  }
  return *this;
}

TreeNode* BinaryTree::copy(const TreeNode * origNode)
{
  if(!origNode) return NULL;
  TreeNode *currentNode=new TreeNode(origNode->value,origNode->leftSize);
  if(origNode->leftNode) currentNode->leftNode=copy(origNode->leftNode);
  if(origNode->rightNode) currentNode->rightNode=copy(origNode->rightNode);
  return currentNode;
}

bool BinaryTree::equal(const TreeNode *thisNode,  const TreeNode *compareNode)
{
  if(!thisNode && !compareNode) return true;
  if(thisNode && compareNode && thisNode->value==compareNode->value && equal(thisNode->leftNode,compareNode->leftNode) &&equal(thisNode->rightNode,compareNode->rightNode))
    return true;
  return false;  
}

void BinaryTree::deleteTree(TreeNode** currentNode)
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

void BinaryTree::preorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    std::cout<<currentNode->value<<" ";
    preorderVec.push_back(currentNode->value);
    preorder(currentNode->leftNode);
    preorder(currentNode->rightNode);
  }
}



void BinaryTree::inorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    inorder(currentNode->leftNode);
    std::cout<<currentNode->value<<" ";
    inorderVec.push_back(currentNode->value);
    inorder(currentNode->rightNode);
  }
}


void BinaryTree::postorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    postorder(currentNode->leftNode);
    postorder(currentNode->rightNode);
    std::cout<<currentNode->value<<" ";
    //postorderVec.push_back(currentNode->value);
  }
}


void BinaryTree::levelorderQueue()
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
}

void BinaryTree::levelorderLeftSizeQueue()
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
}

int main()
{
  BinaryTree< testTree;
} 
