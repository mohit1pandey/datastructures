/* Infix to Prifix with paranthesis*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

/* to check for operand */
bool is_operand(char c){
  if(c>='0'&&c<='9')return true;
 else if(c>='a'&&c<='z')return true;
 else if(c>='A'&&c<='Z')return true;
else return false;
    }


/* to check for operator */
bool is_operator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return true;
    else return false;
}
/* to assign weight to characters*/
int weight_op(char c){
    int weight;
    switch (c)
    {
    case  '+':
    case '-':
    weight=1;
    break;
    case  '*':
    case  '/':
    weight=2;
    break;
    case '^':weight=3;
    break;
    }
    return weight;
}

/* to check weather the stack top has higher precedence or not */

bool has_higher_precedance(char op1/*s.top()*/,char op2){

int wop1=weight_op(op1);
int wop2=weight_op(op2);
if(wop1==wop2){
    if(op1=='^')return false;
    else return true;
}
return wop1>wop2?true:false;
}
/* Function to convert Infix to Postfix */

string infix_to_postfix(string exp){
    int i=0;
    stack<char>s;
   string postfix="";
for(i=0;i<=exp.length();i++){

if(exp[i]==','||exp[i]==' ') continue;

//if operand

else if(is_operand(exp[i])){
postfix +=exp[i];
}
//if operator
//in stack till ( comes do poping

else if(is_operator(exp[i])){
 while (!s.empty()&& has_higher_precedance(s.top(),exp[i])&&s.top()!='(')
 {
   postfix+=s.top();
   
   s.pop(); 
 }   
   s.push(exp[i]);

}
//if exp[i]=( push to stack

else if(exp[i]=='(') s.push(exp[i]);

// when no more poping remains so we reach at ) and then we will pop all the elements

else if(exp[i]==')'){
    while (s.top()!='(')
    {
        postfix+=s.top();
        s.pop();
    }
    s.pop();
}
}
// pop all the remaing operators in the stack
   while (!s.empty())
   {
      postfix+=s.top();
      s.pop();
   }
   return postfix;
}


/* MAIN FUNCTION */
int main(){
 
 string exp;
 cout<<"Enter The Infix Expression :"<<endl;
 getline(cin,exp);
 string postfix=infix_to_postfix(exp);
 cout<<"Postfix Eq :"<<postfix;
return 0;



}