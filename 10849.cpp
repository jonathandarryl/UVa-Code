#include<iostream>
#include<stdlib.h>

using namespace std;

int main(void){
    int x1,x2,y1,y2,test,test2,dimension;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>test2>>dimension;
        for(int j=0;j<test2;j++){
            cin>>x1>>y1>>x2>>y2;
            if((x1 + y1)%2 == (x2 + y2)%2){
                if(x1 == x2 && y1 == y2)
                    cout<<"0"<<endl;
                else if(abs(x1-x2) == abs(y1-y2))
                    cout<<"1"<<endl;
                else
                    cout<<"2"<<endl;
            }
            else
                cout<<"no move"<<endl;
        }
    }
    return 0;
}
