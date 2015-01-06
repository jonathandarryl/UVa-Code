#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void){
    char input[51], remember[51];
    int length;
    while(scanf("%s",input)){
        if(input[0]=='#')
            return 0;
        length = strlen(input);
        strcpy(remember,input);
        next_permutation(input,input+length);
        if(strcmp(remember,input)<0)
            cout<<input;
        else
            cout<<"No Successor";
        cout<<endl;
    }

    return 0;
}
