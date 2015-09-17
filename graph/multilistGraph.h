#include"graph.h"
#include<iostream>
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class multilistGraph: public graph{
  public:
    listGraph():{}

    int addVertex(std::string name);
    //void deleteVertex(int index);
    
    void addEdge(int indexOne, int indexTwo,int weight);
    bool deleteEdge(int indexOne,int indexTwo);
    
    bool searchEdge(int indexOne,int indexTwo);
    void listAdjacent(int index);

    void clearEdge(int index);
    bool isEmpty();
    void printMatrix();
  private:
    typedef struct{
      int vertexOne;
      int vertexTwo;
      Edge* eDgeOne;
      Edge* nodeTwo;
    } Edge;
    std::vector<Edge*> nodeList;
};
