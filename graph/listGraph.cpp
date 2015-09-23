#include"listGraph.h"

std::vector<int> listGraph::DFS(int index){
     ;
}

std::vector<int> listGraph::BFS(int index){
     ;
}

int listGraph::addVertex(std::string name){
  Node *newNode=new Node(nodeList.size(),0,NULL);
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
  Node* currentNode=nodeList.at(indexOne)->nextNode;

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
  std::vector< std::vector<int> > matrix(listSize,std::vector<int>(listSize));

  for (int nodeNum=0;nodeNum<listSize;nodeNum++){
    currentNode=nodeList.at(nodeNum)->nextNode;
    while (currentNode){
         matrix.at(nodeNum).at(currentNode->index)=currentNode->weight;
         currentNode=currentNode->nextNode;
    }
  }
  std::cout<<" "; 
  for (int i=0;i<listSize;i++){
     std::cout<<" "<<vertexName.at(i);
  }
  std::cout<<std::endl;
  for (int i=0;i<listSize;i++){
     std::cout<<vertexName.at(i)<<" ";
     for (int j=0;j<listSize;j++){
       std::cout<<matrix.at(i).at(j)<<" ";   
     }
     std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

int main()
{

listGraph a;
std::cout<<"empty"<<a.isEmpty()<<std::endl;

a.addVertex("A");
a.printMatrix();

a.addVertex("B");
a.printMatrix();


a.addVertex("C");
a.printMatrix();


a.addEdge(0,2);
a.printMatrix();

a.addEdge(0,1);
a.printMatrix();

a.deleteEdge(1,2);
a.printMatrix();

std::cout<<"empty"<<a.isEmpty()<<std::endl;
}
