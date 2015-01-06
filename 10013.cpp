#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int testcase,num,test;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        short a[1000000] = {0};
        cin>>num;
        for(int j=1;j<=num;j++){
            cin>>a[j]>>test;
            a[j]+=test;
        }
        for(int j=num;j>0;j--){
            a[j-1]+=a[j]/10;
            a[j] = a[j]%10;
        }
        if(a[0]==1)
            cout<<"1";
        for(int j=1;j<=num;j++)
            cout<<a[j];
        cout<<endl;
        if(i!=testcase-1)
            cout<<endl;
    }
    return 0;
}
