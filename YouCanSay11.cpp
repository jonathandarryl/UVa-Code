#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    string input;
    int sum[2];
    int length;
    while(cin>>input){
        if(input.length()==1 && input=="0")
            break;
        sum[0] = sum[1] = 0;
        length = input.length();
        for(int i=0;i<length;i++){
            if(i%2==0)
                sum[0]+=input.at(i)-'0';
            else
                sum[1]+=input.at(i)-'0';
        }
        cout<<input<<" is ";
        if(sum[0]%11 == sum[1]%11)
            cout<<"a multiple of 11."<<endl;
        else
            cout<<"not a multiple of 11."<<endl;
    }
    return 0;
}
