#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main(void){
    int test;
    char input[12];
    scanf("%d\n",&test);
    for(int i=0;i<test;i++){
        scanf("%s",input);
        sort(input,input+strlen(input));
        do{
            printf("%s\n",input);
        }while(next_permutation(input,input+strlen(input)));
        cout<<endl;
    }
    return 0;
}
