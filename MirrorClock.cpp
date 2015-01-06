#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(void){
    int test, hour, min;
    string input;
    cin>>test;
    for(int i=0;i<test;i++){
        scanf("%d:%d",&hour,&min);
        min = 60 - min;
        if(min == 60)
            min = 0;
        hour = 12-hour - 1;
        if(min==0)
            hour++;
        if(hour <= 0)
            hour = 12+hour;
        if(hour<10)
            cout<<"0"<<hour<<":";
        else
            cout<<hour<<":";
        if(min<10)
            cout<<"0"<<min;
        else
            cout<<min;

            cout<<endl;
    }
    return 0;
}
