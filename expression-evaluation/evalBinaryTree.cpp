#include"evalBinaryTree.h"

void EvalBinaryTree::calculate()
{
  // 1. to get expression from string to vector<sting>&
  // 2. build tree
  // 3. evaluation by postorder
  infix.push_back("1");
  infix.push_back("*");
  infix.push_back("(");
  infix.push_back("2");
  infix.push_back("+");
  infix.push_back("3");
  infix.push_back(")");
  infix.push_back("*");
  infix.push_back("(");
  infix.push_back("4");
  infix.push_back("+");
  infix.push_back("5");
  infix.push_back(")");
    std::vector<std::string>::iterator iVec=infix.begin();
    std::cout<<"infix: ";
    for(;iVec!=infix.end();iVec++)
    {
        std::cout<<*iVec<<" ";
    }
    std::cout<<std::endl; 
  do{
        std::cout<<"Please"<<std::endl;
        std::string inputExpr;
        //clear the data member of tree
        infix.clear();
        deleteTree();
        getline(std::cin,inputExpr);
        getInfix(inputExpr);
        postorderEval();
        postorder();
        std::cout<<std::endl;
  }while(0);
}

void EvalBinaryTree::postorderEval(TreeNode* node)
{

   if(node){
      if(node->leftNode) postorderEval(node->leftNode);
      if(node->rightNode) postorderEval(node->rightNode);
      switch((node->data).at(0)){
          case '+': node->value = node->leftNode->value + node->rightNode->value; break;
          case '-': node->value = node->leftNode->value - node->rightNode->value; break;
          case '*': node->value = node->leftNode->value * node->rightNode->value; break;
          case '/': node->value = node->leftNode->value / node->rightNode->value; break;
          default:
          std::istringstream ( node->data ) >> node->value;
          break;
      }
   }
}

TreeNode* EvalBinaryTree::buildTree(std::vector<std::string>::iterator iBegin)
{   
    
    while(iBegin!=infix.end() && "("==*iBegin){
       iBegin++;
    }
    std::cout<<"Hi1: "<<*iBegin<<std::endl;
    std::cout<<"Hi2: "<<*(iBegin+1)<<std::endl;
    std::cout<<"Hi3: "<<*(iBegin+2)<<std::endl;
    TreeNode *leftNode=new TreeNode(*iBegin);
    TreeNode *root=new TreeNode(*(iBegin+1));


    root->leftNode=leftNode;
    iBegin=iBegin+2;

    if(infix.end()==iBegin+1){
       root->rightNode=new TreeNode(*iBegin);
    }
    else if("("==*iBegin){
       root->rightNode=buildTree(iBegin+1);
    }
    else if("*"==*(iBegin+1) || "/"==*(iBegin+1)){
      if("("==*(iBegin+2)){
          leftNode=root; // creat new Tree
          root=new TreeNode(*(iBegin+1)); //"*"
          root->leftNode=leftNode;
          iBegin++;// "("
           root->rightNode=buildTree(iBegin+1); //next to "("
       } 
       else 
          root->rightNode=buildTree(iBegin);
    }
    else if(")"==*(iBegin+1) ){// || "+"==*(iBegin+1) || "-"==*(iBegin+1) ){
       root->rightNode=new TreeNode(*iBegin);
       iBegin++; // now is ) + -
       if(")"==*iBegin){
          iBegin++; // now is in opeator next to ")"
          if(infix.end()==iBegin) return root;
       }

       leftNode=root; // creat new Tree
       root=new TreeNode(*iBegin);
       root->leftNode=leftNode;
       iBegin++;
       if(infix.end()==iBegin+1) root->rightNode=new TreeNode(*iBegin);
       else root->rightNode=buildTree(iBegin);
    }
    else if("+"==*(iBegin+1) || "-"==*(iBegin+1)){
       if("("==*(iBegin+2)){
          leftNode=root; // creat new Tree
          root=new TreeNode(*(iBegin+1)); //"*"
          root->leftNode=leftNode;
          iBegin++;// "("
           root->rightNode=buildTree(iBegin+1); //next to "("
       }
       else
       root->rightNode=new TreeNode(*iBegin);

       iBegin++; // now is in +-
       leftNode=root;
       root=new TreeNode(*iBegin);
       root->leftNode=leftNode;
       iBegin++;
       if(infix.end()==iBegin+1) root->rightNode=new TreeNode(*iBegin);
       else root->rightNode=buildTree(iBegin);
    }
    return root;
}


void EvalBinaryTree::getInfix(std::string &inputExpr)
{

    bool negative=false;
    int numNegative=0;
    std::string num;
    std::string::iterator iter=inputExpr.begin();
    std::string showExpr;
    int leftParen=0;

    infix.clear();

    if(iter==inputExpr.end())
       throw std::runtime_error("no Expression");

    while(iter!=inputExpr.end()){
        switch(*iter){
            case ' ': // to check" 3+4"

                if(isdigit(*(iter+1)) && isdigit(*(iter-1))){ //ex. 2+3 4+5
                   throw std::runtime_error("there is a blank between numbers");
                }
                else{
                   iter=inputExpr.erase(iter);
                   break;
                }
            case '(':
                if(iter!=inputExpr.begin() && ( isdigit(*(iter-1)) || ')'==*(iter-1) ) ){
                   infix.push_back("*");
                   showExpr+="*";
                }
                infix.push_back("(");
                showExpr+="(";
                ++iter;
                break;
            case ')':
                if(iter!=inputExpr.begin() && *(iter-1)=='('){
                   throw std::runtime_error("Wrong expression: no expression between ( and )");
                }
                infix.push_back(")");
                showExpr+=")";
                ++iter;
                break;
            case '+':
                if(iter==inputExpr.begin()){
                   throw std::runtime_error("Wrong expression: lack of NUMBER in front of +");
                }

                else if((*(iter-1)=='+'||*(iter-1)=='-'|| *(iter-1)=='*')||*(iter-1)=='/'){
                   throw std::runtime_error("Wrong expression: lack of NUMBER between +-*/ and +");
                }
                else if(inputExpr.end()==(iter+1)){
                   throw std::runtime_error("Wrong expression: lack of NUMBER after +");
                }
                infix.push_back("+");
                showExpr+="+";
                ++iter;
                break;

            case '-':
               if( ( iter==inputExpr.begin() || '('==*(iter-1) )|| ( iter!=inputExpr.begin() && ( '+'==*(iter-1) || '-'==*(iter-1)||
                        '*'==*(iter-1) || '/'==*(iter-1) ) ) ){
                   negative=true;
                   //infix.push_back("(");
                   showExpr+="(-";
                   numNegative++;
                   ++iter;
                   break;
                }
                else if(iter==inputExpr.end()){
                   throw std::runtime_error("Wrong expression: lack of NUMBER after -");
                }
                infix.push_back("-");
                showExpr+="-";
                ++iter;
                break;
            case '*':
            case '/':
                if(iter==inputExpr.begin()){
                   throw std::runtime_error("Wrong expression: lack of NUMBER in front of * or /");
                }

                else if((*(iter-1)=='+'||*(iter-1)=='-'|| *(iter-1)=='*')||*(iter-1)=='/'){
                   throw std::runtime_error("Wrong expression: lack of NUMBER between operator and */");
                }
                else if(inputExpr.end()==(iter+1)){
                   throw std::runtime_error("Wrong expression: lack of NUMBER after * or /");
                }
                else if('/'==*(iter) && '0'==*iter){
                   throw std::runtime_error("Wrong expression: use 0 to divide");
                }
                infix.push_back(std::string(1,*iter));
                showExpr+=*iter;
                ++iter;
                break;
            default://for number
                num.clear();
                if( ')'==*(iter-1) ){
                   infix.push_back("*");
                   showExpr+="*";
                }

                std::string::iterator iterBegin=iter;
                do{
                    ++iter;
                }while(isdigit(*iter));

                num.insert(num.end(),iterBegin,iter);
                showExpr+=num;

                if(negative){
                   if(numNegative%2==1){
                      num.insert(num.begin(),'-'); //no blank
                   }
                }

                infix.push_back(num);
                if(negative){
                   negative=false;
                   while(numNegative--){
                         showExpr+=")";
                   }
                 }
            }
    }

    std::cout<<"Expression: ";
    std::cout<<showExpr<<std::endl;
    std::vector<std::string>::iterator iVec=infix.begin();
    std::cout<<"infix: ";
    for(;iVec!=infix.end();iVec++)
    {
        std::cout<<*iVec;//<<" ";
    }
    std::cout<<std::endl;
}

void EvalBinaryTree::deleteTree(TreeNode** currentNode)
{
  if(*currentNode){
    deleteTree(&((*currentNode)->leftNode));
    deleteTree(&((*currentNode)->rightNode));
    // When delete pointer, the value of the pointer is non-defined
    // Hence, we set the pointer to NULL after pointer deletion.
    // Notice that we must use double point here  
    delete *currentNode; 
    *currentNode=NULL; 
  } 
}

int main()
{
  EvalBinaryTree tree;
  tree.calculate();
  //testEval.doEvaluation();
  return 0;
}
