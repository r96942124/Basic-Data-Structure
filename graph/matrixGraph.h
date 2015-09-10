#include"graph.h"

class matrixGraph: public graph{
  public:
      ;
  private:
  std::map<int,int> indexMap;
  std::stack<int> indexUnused;
  int indexTop;
  std::vector<std::vector<int>> matrix;
};
