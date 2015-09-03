#include"BinaryHeap.h"

/*void BinaryHeap::insert(int key){
  
}*/

int BinaryHeap::deleteMinA(){
  if(data.empty()) throw std::runtime_error("empty Heap");
  int min=data.at(0);
  int lastValue=*(data.end()-1);
  data.erase(data.end()-1);
  int index=1,nextIndex=2;
  
  // for nexIndex==data.size(), it means only one child which is the last node in heap 
  while(nextIndex <= data.size()){
    if( nextIndex < data.size() && data.at(nextIndex-1) > data.at(nextIndex) ) nextIndex++;
    if(lastValue < data.at(nextIndex-1) ){
       data.at(index-1)=lastValue;
       break;
    }
    data.at(index-1)=data.at(nextIndex-1);
    index=nextIndex;
    nextIndex=2*index;
  }
  data.at(index-1)=lastValue; 
  return min;
}

int BinaryHeap::deleteMinB(){
  if(data.empty()) throw std::runtime_error("empty Heap");
  int min=data.at(0);
  data.at(0)=*(data.end()-1);
  data.erase(data.end()-1);
  int index=1,nextIndex=2;

  while(nextIndex <= data.size()){
    if(nextIndex < data.size() && data.at(nextIndex-1) > data.at(nextIndex) ) {
       nextIndex++;
    }
    if(data.at(index-1) < data.at(nextIndex-1) ){
       break;
    }
    int temp=data.at(index-1);
    data.at(index-1)=data.at(nextIndex-1);
    data.at(nextIndex-1)=temp;
    index=nextIndex;
    nextIndex=2*index;
  }
  return min;
}

void BinaryHeap::deleteData(int key){
  int index=search(key);

  if(index==data.size()){
      data.erase(data.end()-1);
  }
  else if(index){
      data.at(index-1)=*(data.end()-1);
      data.erase(data.end()-1);

      if(index/2 && data.at(index-1) < data.at(index/2-1) ){
        int curIndex=index, parentIndex=index/2;
        do{
          int temp=data.at(curIndex-1);
          data.at(curIndex-1)=data.at(parentIndex-1);
          data.at(parentIndex-1)=temp;
          curIndex=parentIndex;
          parentIndex=curIndex/2;
        }while(parentIndex && data.at(curIndex-1) < data.at(parentIndex-1));
      }
      else{ 
        int curIndex=index, childIndex=index*2;
        while(childIndex <= data.size()){
          if(childIndex < data.size() && data.at(childIndex-1) > data.at(childIndex)) childIndex++;
          if(data.at(childIndex-1) > data.at(curIndex-1) ){ 
            return;
          }
          int temp=data.at(curIndex-1);
          data.at(curIndex-1)=data.at(childIndex-1);
          data.at(childIndex-1)=temp;
          curIndex=childIndex;
          childIndex=curIndex*2;
        }
      }
  }
  else{
    std::cout<<"Don't find key="<<key<<std::endl;
  }
}

int BinaryHeap::search(int key){
  int i=0;
  for(i=0;i<data.size();i++){
    if(data.at(i)==key)
       return i+1;
  }
  return 0;
}


int main(){
  BinaryHeap test;
  test.data.push_back(1);
  test.data.push_back(5);
  test.data.push_back(3);
  test.data.push_back(9);
  test.data.push_back(10);
  test.data.push_back(7);
  test.data.push_back(4); 
  /*
  test.data.push_back(4);
  test.data.push_back(5);
  test.data.push_back(7);
  test.data.push_back(9);
  test.data.push_back(10);
  */
  test.print();
  test.deleteData(5);  
  test.print();
  test.deleteData(1);
  test.print();
  test.deleteData(9);  
  test.print();
  test.deleteData(4);
  test.print();
  test.deleteData(3); 
  test.print();
  test.deleteData(10);
  test.print();
  test.deleteData(7);
  test.print(); 

}
