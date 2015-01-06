#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long changes(int, int);
int coins[21];
long long change[22][30100];
int main(void){
    for(int i=1;i<=21;i++)
        coins[i-1] = i*i*i;
    memset(change,-1,sizeof change);
    int input;
    while(cin>>input){
        cout<<changes(input,0)<<endl;
    }
    return 0;
}

long long changes(int money, int value){
    if(money==0)    return 1;
    if(money<0 || value>=21)     return 0;
    if(change[value][money]!=-1)   return change[value][money];
    return change[value][money] = changes(money-coins[value],value) + changes(money,value+1);
}
