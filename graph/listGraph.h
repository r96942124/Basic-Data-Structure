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
    void addVertex(const char &vertex);
    void addEdge(const char &vertexOne,const char &vertexTwo);
    void deleteVertex(const char &vertex);
    void deleteEdge(const char &vertexOne,const char &vertexTwo);
    bool searchEdge(const char &vertexOne,const char &vertexTwo);
    //void listAdjacent(char & vertex);

    //void addVertex(int index);
    void addEdge(int indexOne, int indexTwo);
    void deleteVertex(int index);
    void deleteEdge(int indexOne,int indexTwo);
    bool searchEdge(int indexOne,int indexTwo);
    //void listAdjacent(int index);

    void clearEdge(int index);
    bool isEmpty();
    void printMatrix();
  private:
    std::vector<Node*> 
};
