#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(void){
    int prime[10001] = {1};
    int a,b,j, k, counter;
    long long test;
    for(int i=1;i<=10000;i++){
        test = i*i + i + 41;
        if(test%2!=0){
            k=sqrt(test);
            for(j=3;j<=k;j++)
                if(test%j == 0)
                    break;
            if(j>k)
                prime[i] = 1;
            else
                prime[i] = 0;
        }
        else{
            prime[i] = 0;
        }
    }
    while(cin>>a>>b){
        counter = 0;
        for(int i=a;i<=b;i++)
            counter+=prime[i];
        printf("%.2lf\n",100.0*counter/(b-a+1)+1e-8);

    }
    return 0;
}
