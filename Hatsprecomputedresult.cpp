#include<iostream>
using namespace std;

int main(void){
    long long res[]={0,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841};
    long long fact[]={0,0,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
    int test,in;
    cin>>test;
    while(test--){
        cin>>in;
        cout<<res[in]<<"/"<<fact[in]<<endl;
    }
    return 0;

}
