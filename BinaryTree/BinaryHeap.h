/*
Use array to implement min binary heap
*/
#include<iostream>

class BinaryHeap{
  publice:
    void Create(std::vector<int> & input);
    void insert(int key);
    int deleteMin();
    int search(int key);
    void delete(int key);
    void print(){ 
        for(int i=0;i<n;i++){std::cout<<data[i]<<" ";}
        std::cout<<std::endl;
    }
  private:
    int n;
    std::vector<int> data;
    void creatTopDown();
    void creatBottomUp();
};
