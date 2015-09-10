#include<iostream>

class graph{
  public:
    virtual void insertVertx(int vertex) = 0;
    virtual void insertEdge(int vertexOne, int verTexTwo) = 0;
    virtual void deleteVertex(int vertex) = 0;
    virtual void DeleteEdge(int vertexOne, int verTexTwo) = 0;
    virtual boolean isEmpty() = 0;
    virtual void listAdjacent(int vertex) = 0;
};
