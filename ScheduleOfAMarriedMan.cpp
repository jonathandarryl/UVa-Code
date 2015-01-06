#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(void){
    int test,startH[2],endH[2],startM[2],endM[2],start[2],end[2];
    int min[1440];
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        for(int j=0;j<2;j++){
            scanf("%d:%d %d:%d",&startH[j],&startM[j],&endH[j],&endM[j]);
            start[j] = startH[j]*60+startM[j];
            end[j] = endH[j]*60 + endM[j];
            if(end[j]<start[j])
                end[j]+=1440;
        }
        cout<<"Case "<<i<<": ";
        if(start[0]<=start[1] && start[1]<=end[0] || start[1]<=start[0] && start[0]<=end[1])
            cout<<"Mrs Meeting"<<endl;
        else
            cout<<"Hits Meeting"<<endl;
        cout<<endl;

    }


    return 0;
}
