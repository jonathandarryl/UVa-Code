#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    string input;
    int test, don;
    long long saving;
    cin>>test;
    saving = 0;
    for(int i=0;i<test;i++){
        cin>>input;
        if(input == "donate"){
            cin>>don;
            saving+=don;
        }
        else if(input == "report"){
            cout<<saving<<endl;
        }
    }
    return 0;
}
