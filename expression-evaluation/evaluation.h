#include<iostream>
#include<stack>
#include<string>
#include<vector>

class expression{
  public:
  void calculate();
  
  private:
  std::vector<std::string> expression;
  std::stack<std::vector<std::string>> postfix;
  
  void evaluation();
  void doPostfix();
}
