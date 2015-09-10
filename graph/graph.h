#include<iostream>

class graph{
  public:
    virtual void addVertx(int vertex) = 0;
    virtual void addEdge(int vertexOne, int verTexTwo) = 0;
    virtual void deleteVertex(int vertex) = 0;
    virtual void deleteEdge(int vertexOne, int verTexTwo) = 0;
    virtual boolean isEmpty() = 0;
    virtual void listAdjacent(int vertex) = 0;
};
