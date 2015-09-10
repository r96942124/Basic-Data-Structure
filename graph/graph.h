#include<iostream>

class graph{
  public:
    void insertVertx(int vertex);
    void insertEdge(int vertexOne, int verTexTwo);
    void deleteVertex(int vertex);
    void DeleteEdge(int vertexOne, int verTexTwo);
    boolean isEmpty();
    void listAdjacent(int vertex);
};
