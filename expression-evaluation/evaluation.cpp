#include"evaluation.h"

void Evaluation::calculate()
{
  expression.push_back("1");
  expression.push_back("+");
  expression.push_back("2");
  expression.push_back("*");
  expression.push_back("13");
  
  std::cout<<"Please"<<std::endl;
  getPostfix();
  doEvaluation();
}

void Evaluation::getPostfix()
{
  postfix.clear();
  std::stack<std::string> operand;
  
}

void Evaluation::doEvaluation()
{
  ;
}

int main()
{
  Evaluation testEval;
  testEval.calculate();
  return 0;
}
