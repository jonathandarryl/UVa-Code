#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

string input[100];
string rule;
string alpha[]={"0","1","2","3","4","5","6","7","8","9"};
void comb(int now, int num, int strnow, vector<string> v, int maximum){
    if(now==maximum){
        for(int i=0;i<maximum;i++)
            cout<<v.at(i);
        cout<<endl;
        return;
    }
    else{
        if(rule.at(now)=='#'){
            v.push_back(input[strnow]);
            comb(now+1,num,strnow,v,maximum);
        }
        else if(rule.at(now)=='0'){
            for(int i=0;i<10;i++){
                v.push_back(alpha[i]);
                comb(now+1,i+1,strnow,v,maximum);
                v.pop_back();
            }

        }

    }
}

int main(void){
    int test,code;
    bool contain;
    vector<string> v;
    while(cin>>test){
        for(int i=0;i<test;i++)
            cin>>input[i];
        cout<<"--"<<endl;
        cin>>code;
        for(int j=0;j<code;j++){
            cin>>rule;
            contain = false;
            for(int k=0;k<rule.length();k++)
                if(rule.at(k)=='#'){
                    contain = true;
                    break;
                }
            if(contain){
                for(int k=0;k<test;k++){
                    v.clear();
                    comb(0,0,k,v,rule.length());
                }
            }
            else
                comb(0,0,0,v,rule.length());
        }
    }
    return 0;
}
