#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int input;
    long long res;
    while(scanf("%d",&input)==1){
        res = input/2+1;
        res = res*(res+1)/2.0;
        printf("%lld\n",res);
    }
    return 0;
}
