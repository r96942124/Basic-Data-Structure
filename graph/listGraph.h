#include"graph.h"
#include<iostream>
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class listGraph: public graph{
  public:
    listGraph():{}

    void addVertex(int index);
    int deleteVertex(int index);
    
    void addEdge(int indexOne, int indexTwo,int weight);
    void deleteEdge(int indexOne,int indexTwo);
    
    bool searchEdge(int indexOne,int indexTwo);
    void listAdjacent(int index);

    void clearEdge(int index);
    bool isEmpty();
    void printMatrix();
    void printMatrix(std::string vertexName);
  private:
    typedef struct{
      int index;
      Node* nextNode;
    } Node;
    std::vector<Node*> nodeList;
};
