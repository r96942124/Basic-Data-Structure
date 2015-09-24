#include"tree.hpp"

void Tree::levelOrderQueue()
{
  std::queue<TreeNode*> nodeQueue;
  TreeNode *currentNode=root;
  int childIndex=0;
  if(!root) return;
  nodeQueue.push(root);
  do{
    currentNode=nodeQueue.front();
    nodeQueue.pop();
    std::cout<<currentNode->value<<" ";
    childIndex=0;
    while (childIndex < currentNode->childNode.size()){
         nodeQueue.push(currentNode->childNode.at(childIndex));
         childIndex++;
    }
  }while(!nodeQueue.empty());
}

void Tree::deleteTree(TreeNode** currentNode)
{
  int childIndex=0;
  if(*currentNode){
    while (childIndex < (*currentNode)->childNode.size() ){
        deleteTree( &((*currentNode)->childNode.at(childIndex)) );
        childIndex++;
    }
    // When delete pointer, the value of the pointer is non-defined
    // Hence, we set the pointer to NULL after pointer deletion.
    // Notice that we must use double point here
    //std::cout<<(*currentNode)->value<<" ";
    delete *currentNode;
    *currentNode=NULL;
  }
}


