#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(void){
    string test;
    int quote = 0;
    while(getline(cin,test)){
        for(int i=0;i<test.length();i++){
            if(test.at(i)=='"' && quote == 0){
                cout<<"``";
                quote = 1;
            }
            else if(test.at(i) == '"' && quote == 1){
                cout<<"''";
                quote = 0;
            }
            else
                cout<<test.at(i);
        }

    cout<<endl;
    }
    return 0;
}
