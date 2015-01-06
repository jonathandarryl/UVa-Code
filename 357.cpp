#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long changes(int, int);
int coins[]={1,5,10,25,50};
long long change[6][30100];
int main(void){
    memset(change,-1,sizeof change);
    int input;
    while(cin>>input){
        if(changes(input,0)==1)
            cout<<"There is only 1 way to produce "<<input<<" cents change."<<endl;
        else
            cout<<"There are "<<changes(input,0)<<" ways to produce "<<input<<" cents change."<<endl;
    }
    return 0;
}

long long changes(int money, int value){
    if(money==0)    return 1;
    if(money<0 || value>4)     return 0;
    if(change[value][money]!=-1)   return change[value][money];
    return change[value][money] = changes(money-coins[value],value) + changes(money,value+1);
}
