#include<iostream>          //UVa11059
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    int test, dummy, counter, z;
    int input[20];
    bool first;
    long long pos[20];
    double product;
    z=0;
    while(cin>>test){
        z++;
        product = 0;
        counter = 0;
        memset(pos,0,sizeof pos);
        for(int i=0;i<test;i++){
            cin>>input[i];
            pos[i]=input[i];
            if(pos[i]>product)
                product = pos[i];
            for(int j=0;j<i;j++){
                pos[j]*=input[i];
                if(pos[j]>product)
                    product=pos[j];
            }
        }
        printf("Case #%d: The maximum product is %.0lf.\n\n",z,product);
    }

    return 0;
}
