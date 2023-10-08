// To check wether the parantheis are balanced or not
#include<iostream>
#include<stack>
#include<cstring>

using namespace std;
/* implementation of stack */
stack<char>s1;
/* To check wather the char are pairs or not */
bool is_pair(char open,char close){
if (open=='('&& close ==')') return true;
else if (open=='{'&& close =='}') return true;
else if (open=='['&& close ==']') return true;
else return false;


}

bool is_balanced(char* a,int n){
    int i;
    for ( i = 1; i <n; i++)
    {
    if (a[i]=='['||a[i]=='{'||a[i]=='(')  // right part
    {
    s1.push(a[i]);
    }
    else if (a[i]==']'||a[i]=='}'||a[i]==')')// either right part does not matches or matches
    {
        if ( s1.empty() ||!is_pair(s1.top(),a[i]))  // if both does not match s1.empty =1 is_pair(s1.top(),a[i])=-1
        {
            return false;
        }
        else                                     //both meatchs either s.empty =0 or is_pair(s1.top(),a[i]) = 1
         s1.pop();
        
    }
    
    
    }

    return s1.empty()?true:false;

}


int main(){
char a[50];
cout<<"enter the expression of brackets: ";
gets(a);

int n;
n=strlen(a);

  if (is_balanced(a,n))
  {
    cout<<" paranthesis are balenced ";
  }
  else cout<<"paranthesis are  not balenced ";
  
    return 0;
}



