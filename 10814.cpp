#include<iostream>
#include<string>
using namespace std;
int gcd(unsigned long long int, unsigned long long int);
int main(void){
    string input;
    unsigned long long int a,b,factor;
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>a;
        cin>>input;
        cin>>b;
        factor = gcd(a,b);
        a/=factor;
        b/=factor;
        cout<<a<<" / "<<b<<endl;
    }

    return 0;
}
int gcd(unsigned long long int a, unsigned long long int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}
