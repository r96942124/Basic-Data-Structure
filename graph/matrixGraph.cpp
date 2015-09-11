#include"matrixGraph.h"

void matrixGraph::addVertex(char &vertex)
{
  int index;
  \\O(logN)
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

void matrixGraph::deleteVertex(char &vertex)
{
  std:::map<char,int>::iterator verPair=indexMap.find(vertex);
  if (indexMap.end()==verPair){
    std::cout<<"No such vertex"<<std::endl;
  }
  else{
    int verIndex=verPair->second;
    indexMap.erase(verPair);
    clearEdge(verIndex);
    if ((verIndex+1)==indexTop){
      indexTop=verIndex;
      vertexName.erase(vertexName.end()-1);
      matrix.erase(matrix.end()-1);
    }
    else{
      vertexName.at(verIndex)='\0';
      indexUnused.push(verIndex);
    }
  }
}

void matrixGraph::deleteVertex(int index){
   if (index < matrixSize ){
       clearEdge(index);
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  } 
}

void matrixGraph::clearEdge(int index){
  for (int i=0;i<matrixSize;i++){
    matrix.at(index).at(i)=0;
    matrix.at(i).at(index)=0;
  }
}
