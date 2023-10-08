#include<iostream>
#include<string>
#include<stack>
using namespace std;

/* To check weather the char is operator or not */
bool is_operator(char c);
/* To check weather the char is degit or not */
bool is_degit(char c);
/* Takes op1 op2 and string[i]  [cahr(+,-,*,/)] scan cahr */
int perform_operation(char operation , int op1,int op2);
/* Runs a loop to scan from reight to left and returns the result =stack.top()*/
int evaluate_postfix(string exp);

 
int main(){

  string exp;  
  cout<<"enter the expression :";
 getline(cin,exp);
cout<<"The result is : "<<evaluate_postfix(exp);
    return 0;
}

//1
bool is_operator(char c){
if (c=='+'||c=='-'||c=='*'||c=='/') return true;
return false;
}

//2
bool is_degit(char c){
if (c>='0'&&c <='9') return true;
return false;
}

//3
int perform_operation(char operation , int op1,int op2){
    if (operation=='+') return op1+op2;
   else if (operation=='-') return op1-op2;
   else if (operation=='*') return op1*op2;
   else if (operation=='/') return op1/op2;
   
   else {
    cout<<" operator not found ";
    return -1;
   }
    
}

//4
int evaluate_postfix(string exp){
    
    stack<int>s1;   

    int i=0;
    for ( i = 0; i <exp.length(); i++)
    {/* if cahr is a delemetre so skip */
     if (exp[i]==' '||exp[i]==',') continue;


     /* if char is degits  */
     else if (is_degit(exp[i]))
     {
        int operend=0;
       while (i<exp.length()&& is_degit(exp[i]))  //dont use || (4 5+) =2445 in case of or space and , will also count as degit
       { 
        operend =( operend*10 )  + ( exp[i]-'0');
        i++;  // 1st incrementation in i
       }      // second will be done by for loop it will skip the delemeter 
       i--;   //hence decremantaion if essintail
     
     /* push operend into stack */
     s1.push(operend);
     }
      /* if char[i] is an operator i*/
     else if (is_operator(exp [i]))
     {
        int op2=s1.top();s1.pop(); // first assign and then pop
        int op1=s1.top();s1.pop(); // first assign and then pop
       int result= perform_operation(exp[i],op1,op2);    

     /* push the result into stack */
     s1.push(result);
     }
    }
    /* finaly if all characters are read exit the loop and return the value of top */
    return s1.top();
}