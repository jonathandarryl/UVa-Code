
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
bool comp_ana(char a, char b){
    if(a>='a' && a<='z' && b>='a' && b<='z')
        return a<b;
    if(a>='A' && a<='Z' && b>='A' && b<='Z')
        return a<b;
    if(a>='A' && a<='Z' && b>='a' && b<='z' && tolower(a)!=b)
        return tolower(a)<b;
    if(a>='A' && a<='Z' && b>='a' && b<='z' && tolower(a)==b)
        return true;
    if(a>='a' && a<='z' && b>='A' && b<='Z' && tolower(b)!=a)
        return a<tolower(b);
    if(a>='a' && a<='z' && b>='A' && b<='Z' && tolower(b)==a)
        return false;
}
int main(void){
    int test, length;
    char input[10000];
    scanf("%d\n",&test);
    for(int i=0;i<test;i++){
        scanf("%s",input);
        length = strlen(input);
        sort(input,input+length,comp_ana);
        do{
            printf("%s\n",input);
        }while(next_permutation(input,input+length, comp_ana));
    }
    return 0;
}
