#include<iostream>
#include<stack>
#include<string>
#include<vector>

// for isalnum()
#include<cctype>
// for istringstream
#include<sstream>

class Evaluation{
  public:
  void calculate();
  
  //private:
  std::vector<std::string> expression;
  std::vector<std::string> postfix;
  
  void doEvaluation();
  void getPostfix();
};
