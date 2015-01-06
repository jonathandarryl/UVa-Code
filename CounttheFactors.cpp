#include<iostream>
using namespace std;

int main(void){
    short isPrime[1000001] = {0};
    for(int i=2;i<=1000000;i++){
        if(isPrime[i] == 0){
            for(int j=i;j<=1000000;j+=i){
                isPrime[j]++;
            }
        }
    }
    int input;
    while(cin>>input && input){
        cout<<input<<" : "<<isPrime[input]<<endl;
    }
    return 0;
}
