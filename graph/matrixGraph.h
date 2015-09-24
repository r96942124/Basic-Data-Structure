#include"temp2_graph.h"
#include<iostream>
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class matrixGraph: public graph{
  public:
    matrixGraph():indexTop(0),matrix(std::vector<10,dstd::vector<bool>(10,false)>){}
    void addVertex(char & vertex);
    void addEdge(int indexOne, int indexTwo);
    //void deleteVertex(int index);
    void deleteEdge(int indexOne,int indexTwo);
    bool searchEdge(int indexOne,int indexTwo);
    //void listAdjacent(int index);

    void clearEdge(int index);
    bool isEmpty();
    void printMatrix();
  private:
    int indexTop;
    std::vector< std::vector<bool> > matrix;
};
