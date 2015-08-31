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
    double value;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

class EvalBinaryTree{
  public:
  EvalBinaryTree(TreeNode *node):root(node){}
  EvalBinaryTree():root(NULL){}
  void calculate();

  protected:
  TreeNode *root;
  std::vector<std::string> expression;
  std::vector<std::string> infix;
  void getInfix(std::string &);
  
  TreeNode* buildTree(std::vector<std::string>::iterator iBegin);
  void postorderEval(){
    root=buildTree(infix.begin());
    postorderEval(root);
    std::cout<<root->data<<" "<<"Result: "<<root->value<<std::endl;
  }
  void postorderEval(TreeNode* node);

  void deleteTree(){deleteTree(&root);}
  void deleteTree(TreeNode **node);
  void postorder(){postorder(root);}
  void postorder(TreeNode * currentNode);
};


void EvalBinaryTree::postorder(TreeNode * currentNode)
{
  if(currentNode!=NULL){
    postorder(currentNode->leftNode);
    postorder(currentNode->rightNode);
    std::cout<<currentNode->data<<" ";
    //postorderVec.push_back(currentNode->value);
  }
}
