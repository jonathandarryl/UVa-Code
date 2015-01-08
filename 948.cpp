#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void){
    vector<int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    int test, num;
    for(int i=2;i<40;i++)
        fibo.push_back(fibo[i-1] + fibo[i-2]);
    scanf("%d",&test);
    while(test--){
        scanf("%d",&num);
        bool first = false;
        printf("%d = ",num);
        if(!num)
            printf("0 (fib)\n");
        else{
            for(int i=39;i>1;i--){
                if(num>=fibo[i]){
                    first = true;
                    printf("1");
                    num-=fibo[i];
                }
                else if(first)
                    printf("0");
            }
            printf(" (fib)\n");
        }
    }
    return 0;
}
