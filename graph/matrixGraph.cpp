#include"matrixGraph.h"

// O(logN)
void matrixGraph::addVertex(char &vertex)
{
  int index;
  if (indexMap.end()==indexMap.find(vertex)){
     if (!indexUnused.empty()){
       index=indexUnused.top();
       indexUnused.pop();
     }
     else{
       if (indexTop==matrixSize){
         std::cout<<"out of matrix size range"<<std::endl;
         return;
       }
       else{
         index=indexTop++;
       }
     }
     vertexName.at(index)=vertex;
     map[vertex]=index;
     std::cout<<"Add Vertex: "<<vertex<<std::endl;
  }
  else{
    std::cout<<"Vertex: "<<vertex<<" has existed"<<std::endl;
  }
}

//O(logN)
void matrixGraph::addEdge(char &vertexOne, char &vertexTwo){
  std:::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std:::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  if (verPairOne!=indexMap.end() && verPairTwo!=indexMap.end()){
    int indexOne=verPairOne->second;
    int indexTwo=verPairTwo->second;
    matrix.at(indexOne).at(indexTwo)=1;
    matrix.at(indexTwo).at(indexOne)=1;
  }
}

//O(1)
void matrixGraph::addEdge(int indexOne, int indexTwo){
  if (indexOne < matrixSize && indexTwo < matrixSize ){
    matrix.at(indexOne).at(indexTwo)=1;
    matrix.at(indexTwo).at(indexOne)=1;
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  }
}

// O(logN)
void matrixGraph::deleteEdge(char &vertexOne,char &vertexTwo){
  std:::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std:::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  int indexOne=verPairOne->second;
  int indexTwo=verPairTwo->second;
  matrix.at(indexOne).at(indexTwo)=0;
  matrix.at(indexTwo).at(indexOne)=0;
}

//O(1)
void matrixGraph::deleteEdge(int indexOne, int indexTwo){
  if (indexOne < matrixSize && indexTwo < matrixSize ){
    matrix.at(indexOne).at(indexTwo)=0;
    matrix.at(indexTwo).at(indexOne)=0;
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  }
}

//O(N)
void matrixGraph::deleteVertex(char &vertex)
{
  std:::map<char,int>::iterator verPair=indexMap.find(vertex);
  if (indexMap.end()==verPair){
    std::cout<<"No such vertex"<<std::endl;
  }
  else{
    indexMap.erase(verPair);
    clearEdge(verIndex);
    vertexName.at(verIndex)='\0';
    indexUnused.push(verIndex);
  }
}

// O(N)
void matrixGraph::deleteVertex(int index){
   if (index < matrixSize ){
       clearEdge(index);
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  }
}

// O(N)
void matrixGraph::clearEdge(int index){
  for (int i=0;i<matrixSize;i++){
    matrix.at(index).at(i)=0;
    matrix.at(i).at(index)=0;
  }
}

// O(logN)
bool matrixGraph::searchEdge(char &vertexOne,char &vertexTwo){
  std:::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std:::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  searchEdge(verPairOne->second,verPairTwo->second);
}

//O(1)
bool matrixGraph::searchEdge(int indexOne,int indexTwo){
  if (indexOne < matrixSize && indexTwo < matrixSize ){
   return matrix.at(indexOne).at(indexTwo);
  }
  else{
   return 0;
  }
}


