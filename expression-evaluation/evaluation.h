#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<stdexcept>
// for isdigit()
#include<cctype>
// for istringstream
#include<sstream>


class Evaluation{
  public:
  void calculate();
 
  private:
  typedef enum {lparen,rparen,plus,minus,times,divide,operand,internalUse} precedence;
  static const int a=2;
  std::vector<std::string> expression;
  std::vector<std::string> infix;
  std::vector<std::string> postfix;  
  
  void getInfix(std::string &);
  
  // use postfix 
  precedence getToken(char &symbol);
  void getPostfix();
  void doEvaluation();  
};
