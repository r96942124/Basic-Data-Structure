#include"graph.h"
#include<deque>

class matrixGraph: public graph{
  public:
    matrixGraph():vertexName(std::string(10,'\0'),vertexExist(std::vector<int>(matrixSize)),indexTop(0),matrix(std::vector(matrixSize,std::vector(matrixSize))){}
    void clearEdge(int index);  
    void addVertx(char index);
    void addEdge(int indexOne, int indexTwo);
    void deleteVertex(int index);
    void deleteEdge(int indexOne,int indexTwo);
    bool searchEdge(int indexOne,int indexTwo);
    void listAdjacent(int index);
    
  private:
    const static int matrixSize=10;
    std::string vertexName;
    std::map<char,int> indexMap;
    std::stack<int> indexUnused;
    int indexTop;
    std::vector<std::vector<bool>> matrix;
};
