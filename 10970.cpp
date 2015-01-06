#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int x,y;
    while(cin>>x>>y){
        cout<<x-1 + (y-1)*x;
        cout<<endl;
    }
    return 0;
}
