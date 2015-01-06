#include<iostream>
using namespace std;

int main(void){
    int test, n;
    int age[11];
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>age[j];
        cout<<"Case "<<i<<": "<<age[n/2]<<endl;
    }
    return 0;
}
