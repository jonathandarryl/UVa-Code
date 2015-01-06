#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int test, length, counter, crow;
    string in;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>length;
        getline(cin,in);
        getline(cin,in);
        counter = crow = 0;
        while(counter<length){
            if(in.at(counter)=='.'){
                crow++;
                counter+=3;
            }
            else
                counter++;
        }
        cout<<"Case "<<i<<": "<<crow<<endl;
    }

}
