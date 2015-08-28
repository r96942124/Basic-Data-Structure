#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<stdexcept>
// for isdigit()
#include<cctype>
// for istringstream
#include<sstream>


class TreeNode{
  public:
    friend class BinaryTree;
    TreeNode(std::string data): data(data), leftNode(NULL),rightNode(NULL){;}
    TreeNode(){}
   //protected:
    std::string data;
    int value;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

class BinaryTree{
  public:
  BinaryTree(TreeNode *node):root(node){}
  //protected:
  
  TreeNode *root;
  void postEvaluation();
  void inorder(){inorder(root);}
  void inorder(TreeNode *node){
       if(node){
          inorder(node->leftNode);
          std::cout<<node->data;
          inorder(node->rightNode); 
       }
  }
  void postorder(){postorder(root);}
  void postorder(TreeNode *node){
       if(node){
          postorder(node->leftNode);
          postorder(node->rightNode);
          std::cout<<node->data;
       }
  }
};

class Evaluation{
  public:
  void calculatePostfix();
  
  //private:
  typedef enum {lparen,rparen,plus,minus,times,divide,operand,internalUse} precendence;
  static const int a=2;
  std::vector<std::string> expression;
  std::vector<std::string> postfix;
  std::vector<std::string> infix;  
  
  void calculate(); 
  void getInfix(std::string &);
  
  // use postfix 
  precendence getToken(char &symbol);
  void getPostfix();
  void doEvaluation();
  
  // use postorder
  void postorderEval();
  TreeNode* buildTree(std::vector<std::string>::iterator iBegin);
};
