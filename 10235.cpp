#include<iostream>
#include<stdio.h>
using namespace std;
long long reverse(long long);
int main(void){
    bool isPrime[1000001];
    long long input, rev;
    for(int i=2;i<=1000000;i++)
        isPrime[i] = true;
    for(int i=2;i<=1000000;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=1000000;j+=i){
                isPrime[j] = false;
            }
        }
    }
    while(cin>>input){
        cout<<input;
        rev = reverse(input);
        if(isPrime[input]){
            if(isPrime[rev] && input!=rev)
                cout<<" is emirp."<<endl;
            else
                cout<<" is prime."<<endl;
        }
        else
            cout<<" is not prime."<<endl;
    }
    return 0;
}

long long reverse(long long input){
    long long result = 0;
    while(input>0){
        result = result*10 + input%10;
        input/=10;
    }
    return result;
}
