#include"graph.h"
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class matrixGraph: public graph{
  public:
    matrixGraph():vertexName(std::string(10,'\0')),indexTop(0),matrix(std::vector<  std::vector<bool> >(matrixSize,std::vector<bool>(matrixSize))){}
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
    //bool isEmpty();
    //void printMatrix();
  private:
    const static int matrixSize=10;
    std::string vertexName;
    std::map<char,int> indexMap;
    std::stack<int> indexUnused;
    int indexTop;
    std::vector< std::vector<bool> > matrix;
};
