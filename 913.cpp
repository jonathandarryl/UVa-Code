#include <limits>
#include<iostream>
using namespace std;

int main(void){
    long long num;
    long long sum;
    while(cin>>num){
        if(num == 1)
            sum = 1;
        else{
            num = (num+1)/2;
            num*=num;
            sum = 6*(num-1)-3;
        }
        cout<<sum<<endl;

    }

    return 0;
}
