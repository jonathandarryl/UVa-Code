#include<iostream>
#include<string>
using namespace std;
int main(void){
    string input;
    int group, length;
    while(cin>>group && group){
        cin>>input;
        length = input.length()/group;
        for(int i=0;i<group;i++){
            for(int j=length-1;j>=0;j--)
                cout<<input.at(i*length+j);
        }
        cout<<endl;
    }
    return 0;
}
