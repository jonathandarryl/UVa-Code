#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
bool isPrime[100010042];
short prime[10001];
int main(void){
    for(int i=0;i<=100010041;i++)
        isPrime[i] = true;
    for(int i=2;i<=100010041;i++)
        if(isPrime[i])
            for(int j=i+i;j<=100010041;j+=i)
                isPrime[j] = false;
    int a,b;
    for(int i=1;i<=10000;i++)
        prime[i] = 0;
    prime[0] = 1;
    for(int i=1;i<=10000;i++){
        if(isPrime[(int) i*i + i + 41])
            prime[i] = prime[i-1]+1;
        else
            prime[i] = prime[i-1];
    }
    while(cin>>a>>b){
        printf("%.2lf\n",(double)(prime[b] - prime[a]+1)*100/(b-a+1));
    }
    return 0;
}
