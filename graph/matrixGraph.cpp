#include"matrixGraph.h"

// O(logN)
void matrixGraph::addVertex(const char &vertex)
{
  int index;
  if (indexMap.end()==indexMap.find(vertex)){
     if (!indexUnused.ifEmpty()){
       index=indexUnused.topPop();
     }
     else{
       if (indexTop+1==matrixSize){
         std::cout<<"out of matrix size range"<<std::endl;
         return;
       }
       else{
         index=++indexTop;
       }
     }
     vertexName.at(index)=vertex;
     indexMap[vertex]=index;
     std::cout<<"Add Vertex: "<<vertex<<std::endl;
  }
  else{
    std::cout<<"Vertex: "<<vertex<<" has existed"<<std::endl;
  }
}

//O(logN)
void matrixGraph::addEdge(const char &vertexOne,const char &vertexTwo){
  std::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  if (verPairOne!=indexMap.end() && verPairTwo!=indexMap.end()){
    int indexOne=verPairOne->second;
    int indexTwo=verPairTwo->second;
    matrix.at(indexOne).at(indexTwo)=1;
    matrix.at(indexTwo).at(indexOne)=1;
  }
}

//O(1)
void matrixGraph::addEdge(int indexOne, int indexTwo){
  if (indexOne-- < matrixSize && indexTwo-- < matrixSize ){
    matrix.at(indexOne).at(indexTwo)=1;
    matrix.at(indexTwo).at(indexOne)=1;
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  }
}

// O(logN)
void matrixGraph::deleteEdge(const char &vertexOne,const char &vertexTwo){
  std::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  int indexOne=verPairOne->second;
  int indexTwo=verPairTwo->second;
  matrix.at(indexOne).at(indexTwo)=0;
  matrix.at(indexTwo).at(indexOne)=0;
}

//O(1)
void matrixGraph::deleteEdge(int indexOne, int indexTwo){
  if (indexOne-- < matrixSize && indexTwo-- < matrixSize ){
    matrix.at(indexOne).at(indexTwo)=0;
    matrix.at(indexTwo).at(indexOne)=0;
  }
  else{
    std::cout<<"out of matrix size range"<<std::endl;
  }
}

//O(N)
void matrixGraph::deleteVertex(const char &vertex)
{
  std::map<char,int>::iterator verPair=indexMap.find(vertex);
  if (indexMap.end()==verPair){
    std::cout<<"No such vertex"<<std::endl;
  }
  else{
    clearEdge(verPair->second);
    vertexName.at(verPair->second)='\0';
    indexUnused.pushIndex(verPair->second);
    indexMap.erase(verPair);
    
    if (indexTop-1==indexUnused.getSize()){
      indexUnused.resetStack();
      indexTop=-1;
    }
  }
}

// O(N)
void matrixGraph::deleteVertex(int index){
  if (index < matrixSize ){
    --index;
    char vertex=vertexName.at(index);
    deleteVertex(vertex);
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
bool matrixGraph::searchEdge(const char &vertexOne,const char &vertexTwo){
  std::map<char,int>::iterator verPairOne=indexMap.find(vertexOne);
  std::map<char,int>::iterator verPairTwo=indexMap.find(vertexTwo);
  return searchEdge(verPairOne->second,verPairTwo->second);
}


//O(1)
bool matrixGraph::searchEdge(int indexOne,int indexTwo){
  if (indexOne < matrixSize && indexTwo < matrixSize ){
   return matrix.at(indexOne-1).at(indexTwo-1);
  }
  else{
   return 0;
  }
}

bool matrixGraph::isEmpty(){
  return -1==indexTop;
}

void matrixGraph::printMatrix(){
  std::cout<<" ";
  for (int i=0;i<matrixSize;i++){
     if (vertexName.at(i)!='\0'){
       std::cout<<" "<<vertexName.at(i);
     }
  }
  std::cout<<std::endl;

  for (int i=0;i<matrixSize;i++){
     if (vertexName.at(i)!='\0'){
       std::cout<<vertexName.at(i)<<" ";
       for (int j=0;j<matrixSize;j++){
          if (vertexName.at(j)!='\0'){
            std::cout<<matrix.at(i).at(j)<<" ";
          }
       }
       std::cout<<std::endl;
     }
  }

}

int main()
{
  matrixGraph test;
  test.addVertex('a');
  test.printMatrix();
  test.addVertex('b');
  test.printMatrix();
  test.addVertex('c');
  test.printMatrix();
  test.addVertex('d');
  test.printMatrix();
}
