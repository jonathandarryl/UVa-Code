#include<iostream>
#include<string>
using namespace std;

int main(void){
    string input;
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>input;
        if(input.length() == 5)
            cout<<"3";
        else{
            if((input.at(0) == 'o' && input.at(1)=='n') || (input.at(0) == 'o' && input.at(2)=='e') || (input.at(1) == 'n' && input.at(2)=='e'))
               cout<<"1";
            else if((input.at(0) == 't' && input.at(1)=='w') || (input.at(0) == 't' && input.at(2)=='o') || (input.at(1) == 'w' && input.at(2)=='o'))
                cout<<"2";
        }
        cout<<endl;

    }
    return 0;
}
