#include<listGraph.h>

int addVertex(std::string name){
  Node *newNode=new Node(indexTwo,0,NULL);
  nodeList.push_back(newNode);
  vertexName.push_back(name);
  return nodeList.size()==vertexName.size()?nodeList.size():-1;
}

void listGraph::addEdge(int indexOne, int indexTwo,int weight){
  Node *currentNode=nodeList.at(indexOne);
  Node *newNode=new Node(indexTwo,weight,currentNode->nextNode);
  currentNode->nextNode=newNode;
}

bool listGraph::deleteEdge(int indexOne,int indexTwo){
  Node* currentNode=nodeList.at(indexOne)->nextNode;
  Node* preNode=nodeList.at(indexOne);
  Node* nextNode;
  while (currentNode){
       if(currentNode->index==indexTwo){
          //protection
          nextNode=currentNode->nextNode;
          delete currentNode;
          preNode->nextNode=nextNode;
          return true;
       }
       preNode=currentNode;
       currentNode=currentNode->nextNode;
  }
  return false;
}

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
