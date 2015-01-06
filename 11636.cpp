#include<iostream>

using namespace std;

int main(void){
    int test,numcase = 1,counter,n;
    while(cin>>test){
        if(test<0)
            break;
        else{
        cout<<"Case "<<numcase<<": ";
        }
        if(test == 1){
            cout<<"0";
        }
        else{
            n = 1;
            counter = 0;
            while(test>n){
                n*=2;
                counter++;
            }
            cout<<counter;
        }
        numcase++;
        cout<<endl;
    }

    return 0;
}
