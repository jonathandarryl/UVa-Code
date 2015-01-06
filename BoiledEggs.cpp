#include<iostream>

using namespace std;

int main(void){
    int test, numegg, maxegg, maxweight, currentweight, currentegg;
    int egg[30];
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>numegg>>maxegg>>maxweight;
        currentweight = currentegg = 0;
        for(int j=0;j<numegg;j++){
            cin>>egg[j];
        }

        while(currentweight<maxweight && currentegg<maxegg && currentegg<numegg){
            if(currentweight+egg[currentegg]<=maxweight){
                currentweight+=egg[currentegg];
                currentegg++;
            }
            else
                break;
        }
        cout<<"Case "<<i<<": "<<currentegg<<endl;

    }


}
