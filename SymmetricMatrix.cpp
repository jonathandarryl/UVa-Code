#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int test;
    string dummy;
    long long mtx[100][100];
    int dimension;
    bool negative;
    scanf("%d\n",&test);
    for(int i=1;i<=test;i++){
        negative = false;
        scanf("N = %d",&dimension);
        for(int j=0;j<dimension;j++){
            for(int k=0;k<dimension;k++){
                cin>>mtx[j][k];
                if(mtx[j][k]<0)
                    negative = true;
            }
        }
        getline(cin,dummy);
        cout<<"Test #"<<i<<": ";
        if(!negative){
            for(int j=0;j<dimension;j++)
                for(int k=0;k<dimension;k++)
                    if(mtx[dimension-1-j][dimension-1-k]!=mtx[j][k]){
                        negative = true;
                        break;
                    }
            if(negative)
                cout<<"Non-symmetric."<<endl;
            else
                cout<<"Symmetric."<<endl;

        }
        else
            cout<<"Non-symmetric."<<endl;


    }

    return 0;
}
