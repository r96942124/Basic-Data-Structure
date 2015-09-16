#include<iostream>

class graph{
  public:
    virtual void addVertex(char &vertex) = 0;
    virtual void addEdge(char &vertexOne, char &vertexTwo) = 0;
    virtual void deleteVertex(char &vertex) = 0;
    virtual void deleteEdge(char &vertexOne,char &vertexTwo) = 0;
    virtual bool searchEdge(char &vertexOne,char &vertexTwo) = 0;
    virtual void listAdjacent(char & vertex) = 0;

    virtual void addVertex(int index) = 0;
    virtual void addEdge(int indexOne, int indexTwo) = 0;
    virtual void deleteVertex(int index) = 0;
    virtual void deleteEdge(int indexOne,int indexTwo) = 0;
    virtual bool searchEdge(int indexOne,int indexTwo) = 0;
    virtual void listAdjacent(int index) = 0;

    void clearEdge(int index);
    virtual bool isEmpty() = 0;
    virtual void printMatrix()=0;

};
