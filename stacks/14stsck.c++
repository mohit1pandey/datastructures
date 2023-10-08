//reverseal of a string by stacks
#include<iostream>
#include<cstring> //to use strlen
#include <stack>  // to get the implementation of stack
using namespace std;


void reverse( char* c,int n){
stack<char>s;
/* Loop to fill a stack with the data of string */
int i;
for ( i = 0; i < n; i++)

{
s.push(c[i]);
}
/* To reverese the string */
for ( i = 0; i < n; i++)
{
    c[i] =s.top();  // owerwrite
    s.pop();     // performed pop
}


}
int main(){
    char c[51];
    cout<<"emter the string :";
     gets(c);
     
     cout<<"reversed string :";
    reverse(c,strlen(c));
    cout<<c;
    return 0;
}