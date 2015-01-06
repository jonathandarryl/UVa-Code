#include<string.h>
#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(void){
    char lines[2][1000];
    int test;
    map<char,char> cipher;
    scanf("%d",&test);
    getchar();
    getchar();
    for(int i=0;i<test;i++){
        cipher.clear();
        gets(lines[0]);
        gets(lines[1]);
        for(int j=0;j<strlen(lines[0]);j++)
            cipher[lines[0][j]]=lines[1][j];
        printf("%s\n%s\n",lines[1],lines[0]);

        while(true){
            gets(lines[0]);
            if(strlen(lines[0])==0)
                break;
            for(int j=0;j<strlen(lines[0]);j++){
                if(cipher.find(lines[0][j])==cipher.end())
                    printf("%c",lines[0][j]);
                else
                    printf("%c",cipher[lines[0][j]]);
            }
            printf("\n");
        }
        if(i!=test-1)
            printf("\n");


    }

    return 0;
}
