#include"graph.h"
#include<deque>
#include<map>
#include<stack>
#include<vector>

class matrixGraph: public graph{
  public:
  //  matrixGraph():vertexName(std::string(10,'\0')),indexTop(0),matrix(std::vector(matrixSize,std::vector(matrixSize))){}

  private:
    const static int matrixSize=10;
    std::string vertexName;
    std::map<char,int> indexMap;
    std::stack<int> indexUnused;
    int indexTop;
    std::vector< std::vector<bool> > matrix;
};
