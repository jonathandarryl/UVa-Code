#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int a,b,res;
    while(cin>>a>>b && a!=-1 && b!=-1){
        res = b-a;
        if(res<0)
            res=-res;
        if(res>50)
            res = 100-res;
        cout<<res<<endl;
    }
    return 0;
}
