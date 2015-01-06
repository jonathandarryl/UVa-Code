#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

short divide[1000001];
int most[1000001];

int main(void){
    for(int i=2;i<=1000000;i++)
        divide[i]=1;
    divide[1]=0;
    for(int i=2;i<500001;i++)
        for(int j=i;j<=1000000;j+=i)
            divide[j]++;
    most[1]=1;
    for(int i=2;i<=1000000;i++){
        if(divide[most[i-1]]<=divide[i])
            most[i]=i;
        else
            most[i]=most[i-1];
    }
    int test,in;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&in);
        printf("%d\n",most[in]);
    }
    return 0;
}
