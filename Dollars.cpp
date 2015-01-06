#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long changes(int, int);
int coins[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long change[13][30100];
int main(void){
    memset(change,-1,sizeof change);
    int inputd, inputc;
    double writing;
    while(scanf("%d.%d",&inputd,&inputc)){
        if(inputd==0 && inputc == 0)
            return 0;
        inputd = inputd*100 + inputc;
        writing = inputd/100.0;
        printf("%6.2lf%17llu\n",writing,changes(inputd,0));
    }
    return 0;
}

long long changes(int money, int value){
    if(money==0)    return 1;
    if(money<0 || value>10)     return 0;
    if(change[value][money]!=-1)   return change[value][money];
    return change[value][money] = changes(money-coins[value],value) + changes(money,value+1);
}
