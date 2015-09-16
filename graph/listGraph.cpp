#include<listGraph.h>


bool listGraph::searchEdge(int indexOne,int indexTwo){
  Node* currentNode=nodeList.at(index)->nextNode;

  while (currentNode){
       if(currentNode->index==indexTwo)
          return true;
       currentNode=currentNode->nextNode;
  }
  return false;
}

void listGraph::listAdjacent(int index){
  Node* currentNode=nodeList.at(index)->nextNode;
  std::cout<<"Node "<<vertexName.at(index)<<"'s adjacency: ";
  while (currentNode){
       std::cout<<vertexName.at(currentNode->index);
       currentNode=currentNode->nextNode;
  }
}

void listGraph::clearEdge(int index){
  Node* currentNode=nodeList.at(index)->nextNode;
  Node* nextNode;
  while (currentNode){
       nextNode=currentNode->nextNode;
       delete currentNode;
       currentNode=nextNode;
  }
}

bool listGraph::isEmpty(){
  return nodeList.empty();
}

void listGraph::printMatrix(){
  int listSize=nodeList.size();
  Node* currentNode;
  vector< vector<int> > matrix(listSize,vector<int>(listSize));
  
  for (int nodeNum;nodeNum<listSize;nodeNum++){
    currentNode=nodeList.at(nodeNum)->nextNode;
    while (currentNode){
         matrix.at(nodeNum).at(currentNode->index)=currentNode->weight;
         currentNode=currentNode->nextNode;
    }
  }
  
  for (int i=0;i<listSize;i++){
     std::cout<<" "<<vertexName.at(i);
  }
  
  for (int i;i<listSize;i++){
     std::cout<<vertexName.at(i)<<" ";
     for (int j;j<listSize;j++){
        std::cout<<matrix.at(i).at(j)<<" ";   
     }
     std::cout<<std::endl;
  }
}
