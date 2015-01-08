#include<iostream>
using namespace std;

int main(void){
    int sum[1001];
    int test, counter, dummy;
    while(cin>>test && test){
        counter = 0;
        while(test--){
            cin>>dummy;
            if(dummy){
                sum[counter] = dummy;
                counter++;
            }
        }
        if(counter>0){
            for(int i=0;i<counter-1;i++){
                cout<<sum[i]<<" ";
            }
            cout<<sum[counter-1]<<endl;
        }
        else
            cout<<"0"<<endl;
    }
    return 0;
}
