#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm> 

class TreeNode{
  public:
    template<typename U> friend class BinaryTree;
    TreeNode(int value): value(value),leftNode(NULL),rightNode(NULL){;}
    TreeNode(int value,int leftSize): value(value),leftsize(leftSize),leftNode(NULL),rightNode(NULL){;}
  protected:
    int value;
    int leftSize;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

class BinarySearchTree{
  public:
    BinaryTree(const int value){ root = new TreeNode(value,0);}
    BinaryTree(const BinaryTree & copyTree);
    BinaryTree();
    ~BinaryTree(){deleteTree();}
    
    BinaryTree& operator=(const BinaryTree & assignTree);
    bool operator==(const BinaryTree & tree2){return equal(root,tree2.root);}
     
    bool ifEmpty(){ return root==NULL?1:0;}
     
    void insert(int value);
    int searchRank(int rank);
    bool search(int value); 
    void deleteValue(int value);
    void deleteRank(int rank);   
  
    void preorder() {preorder(root);}
    void inorder()  {inorder(root);}
    void postorder(){postorder(root);} 
    void levelorderQueue();
    void levelorderLeftSizeQueue();    

   protected:
    TreeNode *root;
    std::vector preorderVec;
    std::vector inorderVec;
    std::vector postorderVec;
    
    void preorder(TreeNode * currentNode);
    void inorder(TreeNode * currentNode);
    void postorder(TreeNode * currentNode);
    void levelorder(TreeNode * currentNode);

    TreeNode* copy(const TreeNode * origNode);
    void deleteTree(){deleteTree(&root);}
    void deleteTree(TreeNode **node);
    bool equal(const TreeNode *thisNode, const TreeNode *compareNode); 
};
