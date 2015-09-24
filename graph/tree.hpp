#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm> 
#include<new>

class TreeNode{
  public:
    template<typename U> friend class BinaryTree;
    TreeNode(int value): value(value){;}
  //protected:
    int value;
    std::vector<TreeNode *> childNode;
};

class Tree{
  public:
    Tree(const int value){ root = new TreeNode(value);}
    Tree(TreeNode *root):root(root){}
    Tree():root(NULL){};
    ~Tree(){deleteTree();}
    
     
    bool ifEmpty(){ return root==NULL?1:0;}
     
  
    void levelOrder(){levelOrderQueue();}

  protected:
    TreeNode *root;
    
    void levelOrderQueue();

    void deleteTree(){deleteTree(&root);}
    void deleteTree(TreeNode **node);
};

