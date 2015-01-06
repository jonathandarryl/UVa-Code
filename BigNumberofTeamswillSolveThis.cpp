#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void){
    string input1, input2;
    int test, counter1, counter2;
    bool same;
    cin>>test;
    getline(cin,input1);
    for(int i=1;i<=test;i++){
        getline(cin,input1);
        getline(cin,input2);
        cout<<"Case "<<i<<": ";
        if(input1==input2)
            cout<<"Yes"<<endl;
        else{
            same = true;
            counter1 = counter2 = 0;
            for(int i=0;i<input1.length();i++)
                if(input1.at(i)==' '){
                    input1.erase(i,1);
                    i--;
                }
            for(int i=0;i<input2.length();i++)
                if(input2.at(i)==' '){
                    input2.erase(i,1);
                    i--;
                }


            if(input1==input2)
                cout<<"Output Format Error"<<endl;
            else
                cout<<"Wrong Answer"<<endl;
        }
    }
    return 0;
}
