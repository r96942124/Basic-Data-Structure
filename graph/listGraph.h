#include"graph.h"
#include<iostream>
#include<deque>
#include<map>
#include<stack>
#include<vector>
#include<iterator>

class listGraph: public graph{
  public:

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
    struct Node{
      Node(int index,int weight,Node* nextNode):index(index),weight(weight),nextNode(nextNode){}
      int index;
      int weight;
      Node* nextNode;
    };
    std::vector<Node*> nodeList;
};
