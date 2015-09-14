#include"graph.h"
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class matrixGraph: public graph{
  public:
    matrixGraph():vertexName(std::string(10,'\0')),indexTop(-1),matrix(std::vector<  std::vector<bool> >(matrixSize,std::vector<bool>(matrixSize))){}
    void addVertex(char &vertex);
    void addEdge(char &vertexOne, char &vertexTwo);
    void deleteVertex(char &vertex);
    void deleteEdge(char &vertexOne,char &vertexTwo);
    bool searchEdge(char &vertexOne,char &vertexTwo);
    //void listAdjacent(char & vertex);

    //void addVertex(int index);
    void addEdge(int indexOne, int indexTwo);
    void deleteVertex(int index);
    void deleteEdge(int indexOne,int indexTwo);
    bool searchEdge(int indexOne,int indexTwo);
    //void listAdjacent(int index);

    void clearEdge(int index);
    bool isEmpty();
    //void printMatrix();
  private:
    const static int matrixSize=10;
    std::string vertexName;
    std::map<char,int> indexMap;
    int indexTop;
    std::vector< std::vector<bool> > matrix;
    
    class stackInt{
        public:
          stackInt():index(-1){}
          void pushIndex(int key){ array[++index]=key;}
          int topPop(){return array[index--];}
          void resetStack(){index=-1;}
          void getSize(){return index+1;}
          void ifEmpty(){return -1==index;}
        private:
          int array[matrixSize];
          int index;
    } indexUnused;
};
