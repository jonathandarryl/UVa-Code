#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int high[10001],low[10001];
    memset(high,0,sizeof high);
    memset(low,0,sizeof low);
    int i,j,diff;
    i = 2;
    diff = 0;
    while(i<=58){
        j=1;
        while(j<i){
            diff = i*i*i-j*j*j;
            if(diff<=10000){
                if(low[diff]==0 && high[diff]==0){
                    low[diff]=j;
                    high[diff]=i;
                }
                else if(low[diff]>0 && low[diff]>j){
                    low[diff]=j;
                    high[diff]=i;
                }
            }
            j++;
        }
        i++;
    }
    int input;
    while(cin>>input && input){
        if(!low[input])
            cout<<"No solution"<<endl;
        else
            cout<<high[input]<<" "<<low[input]<<endl;
    }

    return 0;
}
