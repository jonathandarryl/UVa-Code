#include<iostream>
using namespace std;

int main(void){
    for(int i=6;i<=200;i++)
        for(int j=2;j<i;j++)
            for(int k=j+1;k<i-1;k++)
                for(int l=k+1;l<i-2;l++)
                    if(i*i*i == (j*j*j + k*k*k + l*l*l))
                        cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
    return 0;
}
