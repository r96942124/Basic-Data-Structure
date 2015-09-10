#include<iostream>

class graph{
  public:
    virtual void addVertx(char &vertex) = 0;
    virtual void addEdge(char &vertexOne, char &vertexTwo) = 0;
    virtual void deleteVertex(char &verTex) = 0;
    virtual void deleteEdge(char &vertexOne,char &verTexTwo) = 0;
    virtual boolean isEmpty() = 0;
    virtual void listAdjacent(char & vertex) = 0;
    virtual void printMatrix()=0;
};
