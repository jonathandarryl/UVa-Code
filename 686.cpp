#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool isPrime[33001];

int main(void){
    int input, counter,mustfind,remember,count1;

	bool found;
	for(int i=2;i<=33000;i++)
        isPrime[i] = true;
    for(int i=2;i<=33000;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=33000;j+=i)
                isPrime[j]=false;
        }
    }
    while(cin>>input && input){
        found = false;
        count1 = 0;
        counter = 0;
        for(int i=2;i<=input;i++){
            if(isPrime[i] && isPrime[input - i] && i>=input-i){
                counter++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
