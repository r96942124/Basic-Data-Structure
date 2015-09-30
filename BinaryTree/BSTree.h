#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm> 
#include<list>

class TreeNode{
  public:
    friend class BinarySearchTree;
    TreeNode(int value): value(value),leftSize(1),leftNode(NULL),rightNode(NULL){;}
    TreeNode(int value,int leftSize): value(value),leftSize(leftSize),leftNode(NULL),rightNode(NULL){;}
    int getValue(){return value;}
  protected:
    int value;
    int leftSize;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

class BinarySearchTree{
  public:
    BinarySearchTree(const int value):treeSize(1){ root = new TreeNode(value,0);}
    BinarySearchTree():root(NULL),treeSize(0){}
    ~BinarySearchTree(){deleteTree();}
    
     
    bool ifEmpty(){ return root==NULL?1:0;}
     
    void insert(int value);
    TreeNode* searchRank(int rank);
    bool search(int value); 
    void deleteValue(int value){
      std::cout<<"delete: "<<value<<std::endl;
      deleteValue(root,value);
      treeSize--;
    }
    //void deleteRank(int rank);   
  
    void preorder() {preorder(root);}
    void inorder()  {inorder(root);}
    void postorder(){postorder(root);} 
    void levelOrder();
    void levelOrderLeftSize();   
   
    void check(){
        for(int i=0;i<treeSize;i++){
            std::cout<<searchRank(i+1)->value<<" ";
        }
        std::cout<<std::endl<<std::endl;
    } 

  protected:
    TreeNode *root;
    int treeSize;
    std::vector<int> preorderVec;
    std::vector<int> inorderVec;
    std::vector<int> postorderVec;
    
    void preorder(TreeNode * currentNode);
    void inorder(TreeNode * currentNode);
    void postorder(TreeNode * currentNode);

    void deleteTree(){deleteTree(&root);}
    void deleteTree(TreeNode **node);
    
    void insert(TreeNode* node,int value,std::list<TreeNode*> &leftSizeList);
    void deleteValue(TreeNode *node,int value);
};
