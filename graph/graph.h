#include<iostream>
#include<vector>
#include<string>

class graph{
  public:
    virtual int addVertex(std::string name) = 0;
    //virtual void deleteVertex(int index) = 0;
    
    virtual void addEdge(int indexOne, int indexTwo){addEdge(indexOne,indexTwo,1);}
    virtual void addEdge(int indexOne, int indexTwo, int weight) = 0;
    virtual bool deleteEdge(int indexOne,int indexTwo) = 0;
    
    int getWeight(int indexOne,int indexTwo);
    
    
    virtual bool searchEdge(int indexOne,int indexTwo) = 0;
    virtual void listAdjacent(int index) = 0;

    virtual void clearEdge(int index) = 0;
    
    virtual bool isEmpty() = 0;
    virtual void printMatrix()=0;
    
    void printNodeName(){
      for(int i;i<vertexName.size();i++){
          std::cout<<"Node "<<i<<" -> "<<vertexName.at(i)<<std::endl;
      }
    }
 protected: 
    std::vector<std::string> vertexName;
};
