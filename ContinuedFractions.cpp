#include<stdio.h>
#include<iostream>
using namespace std;

int main(void){
    int x,y;
    while(cin>>x>>y){
        cout<<"[";
        bool first = true;
        while(true){
            if(first){
                cout<<x/y;
                cout<<";";
                first = false;
            }
            else{
                cout<<x/y;
                cout<<",";
            }
            int z = x%y;
            if(z==1){
                cout<<y<<"]"<<endl;
                break;
            }
            else{
                x = y;
                y = z;
            }
        }
    }
    return 0;
}
