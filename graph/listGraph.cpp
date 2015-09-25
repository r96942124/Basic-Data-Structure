#include"listGraph.h"

TreeNode* listGraph::BFS(int index){
    
    if (index >=  nodeList.size()){
      return NULL;
    }

    std::vector<bool> indexMark(nodeList.size(),false);
    TreeNode *root=new TreeNode(index);
    TreeNode *parentNode;
    TreeNode *childNode;
    std::vector<TreeNode*> vecNode(nodeList.size(),NULL);
  
    Vertex *graphVertex=nodeList.at(index);

    std::vector< std::vector<int> > indexLevel;
    int topLevel=0;
    int num=0;
    
    indexMark.at(index)=true;
    indexLevel.push_back(std::vector<int>(1,index));  
    vecNode.at(index)=root;
     
    while (!indexLevel.at(topLevel).empty()){
         num=0;
         indexLevel.push_back(std::vector<int>());
         while (num < indexLevel.at(topLevel).size()){
              graphVertex=nodeList.at(indexLevel.at(topLevel).at(num));
              parentNode=vecNode.at(graphVertex->index);
  
              while (graphVertex->nextVertex){
                   graphVertex=graphVertex->nextVertex;
                   if (!indexMark.at(graphVertex->index)){
                     indexMark.at(graphVertex->index)=true;
                     indexLevel.at(topLevel+1).push_back(graphVertex->index);
                     childNode = new TreeNode(graphVertex->index);
                     parentNode->childNode.push_back(childNode);
                     vecNode.at(graphVertex->index)=childNode;
                   }
              }
              num++; 
         }
         topLevel++;   
    }
    indexLevel.erase(indexLevel.end()-1);

    /*topLevel=0;
    while (topLevel<indexLevel.size()){
         std::cout<<"Level "<<topLevel<<": ";
         for(num=0;num<indexLevel.at(topLevel).size();num++){
             std::cout<<indexLevel.at(topLevel).at(num);
         }
         std::cout<<std::endl;
         topLevel++;
    }*/
         
    return root;
}

TreeNode* listGraph::DFS(int rootIndex){
     if (rootIndex < nodeList.size()){
       std::vector<bool> indexMark(nodeList.size(),false);
       indexMark.at(rootIndex)=true;
       return DFS(rootIndex,indexMark);
     }
     return NULL;
}

TreeNode* listGraph::DFS(int index, std::vector<bool> &indexMark){
     TreeNode* parentNode=new TreeNode(index);
     Vertex *graphVertex=nodeList.at(index);
     while (graphVertex){
          if (!indexMark.at(graphVertex->index)){
            indexMark.at(graphVertex->index)=true;
            parentNode->childNode.push_back(DFS(graphVertex->index,indexMark));  
          }
          graphVertex=graphVertex->nextVertex;
     }
     return parentNode;
}

int listGraph::addVertex(std::string name){
  Vertex *newVertex=new Vertex(nodeList.size(),0,NULL);
  nodeList.push_back(newVertex);
  vertexName.push_back(name);
  return nodeList.size()==vertexName.size()?nodeList.size():-1;
}

void listGraph::addEdge(int indexOne, int indexTwo,int weight){
  Vertex *currentVertex=nodeList.at(indexOne);
  Vertex *newVertex=new Vertex(indexTwo,weight,currentVertex->nextVertex);
  currentVertex->nextVertex=newVertex;
}

bool listGraph::deleteEdge(int indexOne,int indexTwo){
  Vertex* currentVertex=nodeList.at(indexOne)->nextVertex;
  Vertex* preVertex=nodeList.at(indexOne);
  Vertex* nextVertex;
  while (currentVertex){
       if(currentVertex->index==indexTwo){
          //protection
          nextVertex=currentVertex->nextVertex;
          delete currentVertex;
          preVertex->nextVertex=nextVertex;
          return true;
       }
       preVertex=currentVertex;
       currentVertex=currentVertex->nextVertex;
  }
  return false;
}

bool listGraph::searchEdge(int indexOne,int indexTwo){
  Vertex* currentVertex=nodeList.at(indexOne)->nextVertex;

  while (currentVertex){
       if(currentVertex->index==indexTwo)
          return true;
       currentVertex=currentVertex->nextVertex;
  }
  return false;
}

void listGraph::listAdjacent(int index){
  Vertex* currentVertex=nodeList.at(index)->nextVertex;
  std::cout<<"Vertex "<<vertexName.at(index)<<"'s adjacency: ";
  while (currentVertex){
       std::cout<<vertexName.at(currentVertex->index);
       currentVertex=currentVertex->nextVertex;
  }
}

void listGraph::clearEdge(int index){
  Vertex* currentVertex=nodeList.at(index)->nextVertex;
  Vertex* nextVertex;
  while (currentVertex){
       nextVertex=currentVertex->nextVertex;
       delete currentVertex;
       currentVertex=nextVertex;
  }
}

bool listGraph::isEmpty(){
  return nodeList.empty();
}

void listGraph::printMatrix(){
  int listSize=nodeList.size();
  Vertex* currentVertex;
  std::vector< std::vector<int> > matrix(listSize,std::vector<int>(listSize));

  for (int nodeNum=0;nodeNum<listSize;nodeNum++){
    currentVertex=nodeList.at(nodeNum)->nextVertex;
    while (currentVertex){
         matrix.at(nodeNum).at(currentVertex->index)=currentVertex->weight;
         currentVertex=currentVertex->nextVertex;
    }
  }
  std::cout<<" "; 
  for (int i=0;i<listSize;i++){
     std::cout<<" "<<vertexName.at(i);
  }
  std::cout<<std::endl;
  for (int i=0;i<listSize;i++){
     std::cout<<vertexName.at(i)<<" ";
     for (int j=0;j<listSize;j++){
       std::cout<<matrix.at(i).at(j)<<" ";   
     }
     std::cout<<std::endl;
  }
  std::cout<<std::endl;
}

int main()
{

listGraph a;
//std::cout<<"empty"<<a.isEmpty()<<std::endl;

a.addVertex("0");
a.addVertex("1");
a.addVertex("2");
a.addVertex("3");
a.addVertex("4");
a.addVertex("5");
a.addVertex("6");
a.addVertex("7");
a.addVertex("8");


a.addEdge(1,3);
a.addEdge(1,2);
a.addEdge(2,5);
a.addEdge(2,4);
a.addEdge(2,3);
a.addEdge(3,8);
a.addEdge(3,7);
a.addEdge(4,5);
a.addEdge(5,6);

//a.DFS(0);
Tree b(a.BFS(1));
b.levelOrder();
}
