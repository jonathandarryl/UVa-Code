#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){

    int a,b,c,d,l;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l) && (a||b||c||d||l)){
        int counter = 0;
        long long result;
        for(int i=0;i<=l;i++){
            result = a*i*i + b*i + c;
            if(!(result%d))
                counter++;
        }
        printf("%d\n",counter);
    }
    return 0;
}
