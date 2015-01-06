#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void){

    int test, ages;
    while(scanf("%d",&test) && test){
        int age[101] = {0};
        for(int i=0;i<test;i++){
            scanf("%d",&ages);
            age[ages]++;
        }

        for(int i=1;i<100;i++){
            for(int j=1;j<=age[i];j++){
                if(--test)
                    printf("%d ",i);
                else
                    printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
