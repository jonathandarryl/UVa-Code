#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool isPrime[1000001];

int main(void){
    int input, counter,mustfind,remember,count1;

	bool found;
	for(int i=0;i<=1000000;i++)
        isPrime[i] = true;
    for(int i=2;i<=999990;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=1000000;j+=i)
                isPrime[j]=false;
        }
    }
    while(cin>>input && input){
        found = false;
        count1 = 0;
        for(int i=2;i<1000000;i++){
            if(isPrime[i] && isPrime[input - i]){
                found = true;
                count1 = i;
                break;
            }

        }
        if(found)
            printf("%d = %d + %d\n",input,count1,input - count1);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
