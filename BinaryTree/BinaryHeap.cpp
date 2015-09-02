#include<BinaryHeap.h>

/*void BinaryHeap::insert(int key){
  
}*/

/*int BinaryHeap::deleteMin(int key){
  
}*/

/*void BinaryHeap::delete(int key){
  int index=search(key);
  if(!index){
      data.at(index-1)=*(data.end()-1)
      data.erase(data.end()-1);
      if(index/2 && data.at(index-1) < data.at(index/2-1) ){
        int curIndex=index, parentIndex=index/2;
        do{
          int temp=data.at(curIndex-1);
          data.at(curIndex-1)=data.at(parentIndex-1);
          data.at(parentIndex-1)=temp;
          curIndx=parentIndex;
          parentIndex=curIndex/2;
        }while(parIndex && data.at(curIndex-1) < data.at(parentIndex-1));
      }
      else if(index*2 < data.size()){ 
        int curIndex=index, childIndex=index*2;
        do{
          if(data.at(childIndex-1) > data.at(childIndex)) childIndex++;
          if(data.at(childIndex-1) > data.at(curIndex-1) ){ 
            return;
          }
          int temp=data.at(curIndex-1);
          data.at(curIndex-1)=data.at(childIndex-1);
          data.at(childIndex-1)=temp;
          curIndx=childIndex;
          childIndex=curIndex*2;
        }while(childIndex<data.size());
      }
  }
  else{
    std::cout<<"Don't find key="<<key<<std::endl;
  }
}*/

int BinaryHeap::search(int key){
  int i=0;
  for(i=0;i<data.size();i++){
    if(data.at(i)==key)
       return i+1;
  }
  return 0;
}


int main(){
  
}
