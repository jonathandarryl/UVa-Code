#include<iostream>
#include<stdio.h>

using namespace std;

int main(void){
    int test, pointer;

    bool pos;
    double cost, collected;
    while(scanf("%d",&test) && test){
        cost = collected = 0;
        for(int i=0;i<test;i++){
            cin>>pointer;
            collected+=pointer;
            if(collected<0)
                cost-=collected;
            else
                cost+=collected;
        }
        printf("%.0lf\n",cost);
    }
    return 0;
}
