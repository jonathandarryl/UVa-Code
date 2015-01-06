#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int GCD(int,int);

int main(void){
    int x,total;
    for(int x=2;x<501;x++){
        total=0;
        for(int i=1;i<x;i++)
            for(int j=i+1;j<=x;j++){
                total+=GCD(i,j);
            }
        printf("%d\n",total);
    }
    return 0;
}

int GCD(int i, int j){
    if(!j)
        return i;
    else
        return GCD(j,i % j);
}
