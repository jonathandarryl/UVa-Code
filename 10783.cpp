#include<iostream>

using namespace std;

int main(void){
    int test;
    int start, finish;
    int sum;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>start>>finish;
        sum = 0;
        if(start%2==0)
            start++;
        for(int j=start;j<=finish;j+=2)
            sum+=j;
        cout<<"Case "<<i<<": "<<sum<<endl;
    }

    return 0;
}
