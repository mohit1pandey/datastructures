/* USING SWITCH CASE */
//infix to psostfix
#include <iostream>
using namespace std;
int arr_length(int size){
    return(size/sizeof(int));
}
int main(){

    int a[5]={1,2,3,4,5};
    cout<<arr_length(sizeof(a));
    return 0;
}