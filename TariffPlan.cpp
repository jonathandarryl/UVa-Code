#include<iostream>
using namespace std;

int main(void){
    int test, numcall, interval;
    int sum[2];
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>numcall;
        sum[0] = sum[1] = 0;
        for(int j=0;j<numcall;j++){
            cin>>interval;
            sum[0] +=(interval/30 + 1)*10;
            sum[1] +=(interval/60 + 1)*15;
        }
        cout<<"Case "<<i<<": ";
        if(sum[0]==sum[1])
            cout<<"Mile Juice "<<sum[1]<<endl;
        else if(sum[0]<sum[1])
            cout<<"Mile "<<sum[0]<<endl;
        else
            cout<<"Juice "<<sum[1]<<endl;
    }


    return 0;
}
