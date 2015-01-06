#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    bool found = false;
    for(int i=1;i<=50000;i++){
        found = false;
        for(int j=0;j<i;j++){
            for(int k=j;k<i;k++){
                for(int l=k;l<i;l++){
                    if(j*j*j + k*k*k + l*l*l == i*i*i){
                        cout<<j<<" "<<k<<" "<<l;
                        found = true;
                        break;
                    }
                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        if(!found)
            cout<<"-1";
        cout<<",";
    }
    return 0;
}
