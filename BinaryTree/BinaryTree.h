#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm> 

template<typename T>
class TreeNode{
  public:
    template<typename U> friend class BinaryTree;
    TreeNode(T Tvalue): value(Tvalue), leftNode(NULL),rightNode(NULL){;}
  protected:
    T value;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;
};

template<typename T>
class BinaryTree{
  public:
    BinaryTree(const T value){ root = new TreeNode<T>(value);}
    BinaryTree(const BinaryTree<T> & copyTree);
    BinaryTree();
    ~BinaryTree(){deleteTree();}
    
    BinaryTree<T>& operator=(const BinaryTree<T> & assignTree);
    bool operator==(const BinaryTree<T> & tree2){return equal(root,tree2.root);}
    
    
    
    bool ifEmpty(){ return root==NULL?1:0;}
    
    void addLeft (T value);
    void addRight(T value);
    
    void preorder() {preorder(root);}
    void inorder()  {inorder(root);}
    void postorder(){postorder(root);}
    
    void preorderStack();
    void preorderStack2();
    void preorderStack3();
    void inorderStack();    
    void postorderStack();
    void postorderStack2();
    void postorderStack3(); 
   
    void levelorderQueue();
     
//  protected:
    TreeNode<T> *root;
    std::vector<T> preorderVec;
    std::vector<T> inorderVec;
    std::vector<T> postorderVec;
    
    void preorder(TreeNode<T> * currentNode);
    void inorder(TreeNode<T> * currentNode);
    void postorder(TreeNode<T> * currentNode);
    void levelorder(TreeNode<T> * currentNode);

    TreeNode<T>* copy(const TreeNode<T> * origNode);
    void deleteTree(){deleteTree(&root);}
    void deleteTree(TreeNode<T> **node);
    bool equal(const TreeNode<T> *thisNode, const TreeNode<T> *compareNode);
    
};
