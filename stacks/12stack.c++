// stack is a data type 
// based on last in first out
// can be implemanted by list(array) and linked list

// array based implentation
#include<iostream>
using namespace std;
#define _MAX_SIZE_ 101
 int a[_MAX_SIZE_];
 int Top=-1;
 void push(int data){

     Top++;
    try
    {
     if (Top==_MAX_SIZE_ -1) 
     {
       throw Top;    
     }
     
    }
    catch(int e)
    {
         cout<<"value cannot be more than "<<e<<endl;
    }
    a[Top]=data;
 }
 void pop(){
    Top--;
try
    {
     if (Top<0) 
     {
       throw Top;    
     }
     
    }
    catch(int e)
    {
         cout<<"the stack is empty ";
    }
 }
 int top(){
     return a[Top];
 }
 bool isempty(){
  if (Top==-1)
  {
    return true;
  }
  return false;

 }
 void print(){
    int i;
  for ( i = 0; i <=Top; i++)
  {
    cout<<a[i];
  }
  cout<<endl;

 }
 int main(){
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
   print();
  pop();
   print();
   cout<<top();




 
    return 0;
 }