#include<iostream>
using namespace std;

int main(void){
    bool hartal[3651];
    int test, N,politic[100],party,counter;
    cin>>test;
    for(int i=0;i<test;i++){
        counter = 0;
        cin>>N;
        for(int j=1;j<=N;j++){
            hartal[j] = true;
        }
        cin>>party;
        for(int j=0;j<party;j++){
            cin>>politic[j];
            for(int k=politic[j];k<=N;k+=politic[j])
                hartal[k] = false;
        }
        for(int j=6;j<=N;j+=7){
            hartal[j] = hartal[j+1] = true;
        }
        for(int j=1;j<=N;j++)
            if(!hartal[j])
                counter++;
        cout<<counter<<endl;
    }
}
