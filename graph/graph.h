#include<iostream>

class graph{
  public:
    graph():{}
    virtual void addVertex(int index) = 0;
    virtual void deleteVertex(int index) = 0;
    
    void addEdge(int indexOne, int indexTwo){addEdge(indexOne,indexTwo,1);}
    virtual void addEdge(int indexOne, int indexTwo, int weight) = 0;
    virtual void deleteEdge(int indexOne,int indexTwo) = 0;
    
    int getWeight(int indexOne,int indexTwo);
    
    
    virtual bool searchEdge(int indexOne,int indexTwo) = 0;
    virtual void listAdjacent(int index) = 0;

    virrual void clearEdge(int index) = 0;
    
    virtual bool isEmpty() = 0;
    virtual void printMatrix()=0;
    virtual void printMatrix(std::string vertexName)=0;
    void printNodeName(){
      for(int i;i<vertexNmae.size();i++){
          std::cout<<"Node "<<i<<" -> "<<vertexName.at(i)<<std::endl;
      }
    }
 private: 
    std::vector<std::string> vertexName;
};
