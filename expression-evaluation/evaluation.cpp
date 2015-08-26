#include"evaluation.h"

void Evaluation::calculate()
{
  expression.push_back("1");
  expression.push_back("*");
  expression.push_back("(");
  expression.push_back("2");
  expression.push_back("+");
  expression.push_back("3");
  expression.push_back("+"); 
  expression.push_back("4");
  expression.push_back(")");
   
  std::cout<<"Please"<<std::endl;
  
  // 1. to get expression
  // 2. check the validity for expression
  // 3. add * => 1(2+3) = 1*(2+3)
  
  std::string inputExpr;
  getline(std::cin,inputExpr);
  
  getInfix();
  getPostfix();
  doEvaluation();
}

void Evaluation::getPrefix()
{
 ;
}

void Evaluation::getPostfix()
{
  const int isp[6]={0,19,12,12,13,13};
  const int icp[6]={20,19,12,12,13,13};
  std::stack<std::string> symbol;   
  std::vector<std::string>::iterator iterExpr=expression.begin();

  while(iterExpr!=expression.end()){
    if(isdigit((*iterExpr)[0]) || isdigit((*iterExpr)[1])){
      postfix.push_back(*iterExpr);
    }
    else if(symbol.empty()){
      getToken((*iterExpr)[0]);
      symbol.push(*iterExpr);
    }
    else if(*iterExpr==")"){
      while(!symbol.empty() && symbol.top()!="("){  
        postfix.push_back(symbol.top());
        symbol.pop();
      }
      if(symbol.empty()){
        std::cerr<<"Error: no ("<<std::endl;
        throw std::runtime_error("Error: no (");   
      }
      else symbol.pop();  
    }
    else{
      while(!symbol.empty() && (isp[getToken((symbol.top())[0])] >= icp[getToken((*iterExpr)[0])])){
        postfix.push_back(symbol.top());
        symbol.pop();      
      }
      symbol.push(*iterExpr);
    }
    iterExpr++;
  }

  while(!symbol.empty()){
    if(symbol.top()=="("){
      std::cerr<<"Error: no )"<<std::endl;
      throw std::runtime_error("Error: no )");
    }
    else{
      postfix.push_back(symbol.top());
      symbol.pop();
    }
  }
  
  std::cout<<"postfix: ";
  iterExpr=postfix.begin();
  while(iterExpr!=postfix.end()) std::cout<<*(iterExpr++)<<" ";
  std::cout<<std::endl;
}

Evaluation::precendence Evaluation::getToken(char &symbol)
{
  switch(symbol){
    case '(': return lparen;
    case ')': return rparen;
    case '+': return plus;
    case '-': return minus;
    case '*': return times;
    case '/': return divide;
  }
  std::cerr<<"Error: internalUse"<<std::endl;
  throw std::runtime_error("Error:internalUse");
  return internalUse;
}

void Evaluation::doEvaluation()
{
  //postfix.clear();
  //postfix.push_back("2");
  //postfix.push_back("3");
  //postfix.push_back("4");
  //postfix.push_back("*");
  //postfix.push_back("+");
  
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
std::cout<<std::endl<<numPostfix.top()<<std::endl;
}

  

int main()
{
  Evaluation testEval;
  testEval.calculate();
  //testEval.doEvaluation();
  return 0;
}
