#include<iostream>

class graph{
  public:
    virtual void addVertx(char &vertex) = 0;
    virtual void addEdge(char &vertexOne, char &vertexTwo) = 0;
    virtual void deleteVertex(char &vertex) = 0;
    virtual void deleteEdge(char &vertexOne,char &vertexTwo) = 0;
    virtual bool isEmpty() = 0;
    virtual bool searchEdge(char &vertexOne,char &vertexTwo) = 0; 
    virtual void listAdjacent(char & vertex) = 0;
    virtual void printMatrix()=0;
};
