#include<string>
#include<iostream>
using namespace std;

int main(void){
    string input;
    int test, mcounter, fcounter;
    cin>>test;
    getline(cin,input);
    for(int i=0;i<test;i++){
        getline(cin,input);
        mcounter = fcounter = 0;
        for(int j=0;j<input.length();j+=3){
            if(input.at(j)=='M' && input.at(j+1)=='M')
                mcounter++;
            else if(input.at(j)=='F' && input.at(j+1) == 'F')
                fcounter++;
        }
        if(mcounter==fcounter && input.length()>=5)
            cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    }

}
