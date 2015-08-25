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
  postfix.clear();
  postfix.push_back("2");
  postfix.push_back("3");
  postfix.push_back("4");
  postfix.push_back("*");
  postfix.push_back("+");
  
  std::stack<int> numPostfix;
  int value,operandOne=0,operandTwo;
  std::vector<std::string>::iterator iterPostfix=postfix.begin();
  
  while((iterPostfix)!=postfix.end()){
    
    // to find method
    if(isalnum((*iterPostfix)[0]) || isalnum((*iterPostfix)[1])){
      std::istringstream ( *iterPostfix ) >> value;
      numPostfix.push(value); 
    }
    else{
      operandOne=numPostfix.top();
      numPostfix.pop();
      operandTwo=numPostfix.top();
      numPostfix.pop();
      switch((*iterPostfix)[0])
      {
        case '+':
          numPostfix.push(operandOne+operandTwo);
          break;
        case '-':
          numPostfix.push(operandOne-operandTwo);
          break;
        case '*':
          numPostfix.push(operandOne*operandTwo);
          break;
        case '/':
          numPostfix.push(operandOne/operandTwo);
          break;
        default:
          std::cerr<<(*iterPostfix)<<"Error"<<std::endl;
      }
    }
    iterPostfix++;
  }
  std::cout<<numPostfix.top()<<std::endl;
}

  

int main()
{
  Evaluation testEval;
  //testEval.calculate();
  testEval.doEvaluation();
  return 0;
}
