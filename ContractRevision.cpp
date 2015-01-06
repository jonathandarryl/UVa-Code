#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    char test;
    string testing;
    int length;
    bool firstzero;
    while(cin>>test>>testing){
        if(testing=="0" && test=='0')
            return 0;
        length = testing.length();
        firstzero = true;
        for(int i=0;i<length;i++){
            if(testing.at(i)!=test){
                if(firstzero && testing.at(i)!='0'){
                    cout<<testing.at(i);
                    firstzero = false;
                }
                else if(!firstzero)
                    cout<<testing.at(i);
            }
        }
        if(firstzero)
            cout<<"0";
        cout<<endl;
    }
    return 0;
}
