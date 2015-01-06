#include<stdio.h>       \\UVa12188
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(void){
    char input[10000];
    int length,temp;
    long long total;
    while(gets(input)){
        if(input[0]=='*')
            return 0;
        total = 0;
        length = strlen(input);
        for(int i=0;i<length;i++){
            temp = input[i]- 'a';
            if(temp>13)
                temp = 26-temp;
            total+=temp;
        }
        printf("%lld\n",total);
    }
    return 0;
}
