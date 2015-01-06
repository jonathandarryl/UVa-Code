#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int h, m,s,ms, total;
    while(scanf("%2d%2d%2d%2d",&h,&m,&s,&ms) == 4){
        total=((h*60 + m)*60+s)*100+ms;
        total = total*125/108;
        printf("%07d\n",total);
    }
    return 0;
}
