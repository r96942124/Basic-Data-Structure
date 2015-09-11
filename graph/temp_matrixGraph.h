#include"graph.h"
#include<deque>

class matrixGraph: public graph{
  public:
    void clearEdge(int index);  
  private:
    std::string vertexName;
    std::vector<int> 
    std::map<char,int> indexMap;
    std::stack<int> indexUnused;
    int indexTop;
    std::vector<std::vector<int>> matrix;
};

