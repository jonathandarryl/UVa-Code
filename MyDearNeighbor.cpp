#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    char token[2500];
    char * pch;
    int input, numneighbor;
    cin>>input;
    for(int i=0;i<input;i++){
        cin>>numneighbor;
        for(int j=0;j<numneighbor;j++){
            getline(cin,token);
            pch = strtok(token," ");
        }
    }
}
