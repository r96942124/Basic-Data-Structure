/*
Use array to implement min binary heap
*/
#include<iostream>
#include<vector>

class BinaryHeap{
  public:
    void Create();
    void insert(int key);
    int deleteMinA();
    int deleteMinB();
    int search(int key);
    void deleteData(int key);
    void print(){ 
        for(int i=0;i<data.size();i++){ std::cout<<data.at(i)<<" "; }
        std::cout<<std::endl;
    }
  //private:
    int n;
    std::vector<int> data;
    void creatTopDown(std::vector<int> & input);
    void creatBottomUp();
    void heapify(int key);
};
