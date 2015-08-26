#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<stdexcept>

// for isalnum()
#include<cctype>
// for istringstream
#include<sstream>

class Evaluation{
  public:
  void calculate();
  
  //private:
  typedef enum {lparen,rparen,plus,minus,times,divide,operand,internalUse} precendence;
  static const int a=2;
  std::vector<std::string> expression;
  std::vector<std::string> postfix;
  std::vector<std::string> infix;  

  precendence getToken(char &symbol);
  void doEvaluation();
  void getPostfix();
  void getInfix(std::string &);
};
