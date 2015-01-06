#include<iostream>

using namespace std;

int main(void){
    int device, operation, capacity, max, temp, op, dummy, idx;
    int devicepower[21], on[21];
    bool isBlown;
    idx = 1;
    while(true){
        cin>>device>>operation>>capacity;
        if(device==operation && operation == capacity && capacity == 0)
            break;
            temp = max = 0;
            isBlown = false;
        for(int i=0;i<device;i++){
            cin>>devicepower[i];
            on[i] = 0;
        }
        for(int i=0;i<operation;i++){
            cin>>op;
            if(on[op-1]==0){
                on[op-1] = 1;
                temp+= devicepower[op-1];
                if(max<temp)
                    max = temp;
                if(max>capacity){
                    isBlown = true;
                }
            }
            else if(on[op-1]==1){
                on[op-1] = 0;
                temp-=devicepower[op-1];
            }

        }
        cout<<"Sequence "<<idx<<endl;
        if(isBlown){
            cout<<"Fuse was blown."<<endl;
        }
        else{
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<max<<" amperes."<<endl;
        }
        cout<<endl;
        idx++;
    }
    return 0;
}
