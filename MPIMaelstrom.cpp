#include<iostream>
#include<sstream>
#include<map>
#include<stdio.h>
#include<string.h>
#define INF 1000000
using namespace std;

int main(void){
    int test;
    string in;
    long long data[200][200];
    long long total;
    while(cin>>test){
        if(test==1){
            cout<<"0"<<endl;
        }
        else{
            total = 0;
            for(int i=2;i<=test;i++){
                for(int j=1;j<=i-1;j++){
                    cin>>in;
                    if(in=="x"){
                        data[i][j] = INF;
                        data[j][i] = INF;
                    }
                    else{
                        stringstream(in)>>(data[i][j]);
                        data[j][i] = data[i][j];
                    }
                }
            }
            for(int k=1;k<=test;k++)
                for(int i=1;i<=test;i++)
                    for(int j=1;j<=test;j++)
                        data[i][j] = min(data[i][j],data[i][k]+data[k][j]);
            for(int i=2;i<=test;i++)
                total = max(total,data[1][i]);
            cout<<total<<endl;
        }
    }
    return 0;
}
