#include<iostream>
#include<map>
#include<string.h>
using namespace std;

bool prime[2100];

void sieve(){
    memset(prime,true,sizeof prime);
    prime[0]=prime[1]=false;
    for(int i=2;i<=2100;i++)
        if(prime[i])
            for(int j=i+i;j<=2100;j+=i)
                prime[j]=false;
}
int main(void){
    sieve();
    int test;
    cin>>test;
    string input;
    getline(cin,input);
    map<char,int> parse;
    bool printed;
    for(int i=1;i<=test;i++){
        getline(cin,input);
        parse.clear();
        printed = false;
        for(int j=0;j<input.length();j++){
            parse[input.at(j)]++;
        }
        cout<<"Case "<<i<<": ";
        for(map<char,int>::iterator it=parse.begin();it!=parse.end();it++){
            if(prime[it->second]){
                printed = true;
                cout<<it->first;
            }
        }
        if(!printed)
            cout<<"empty"<<endl;
        else
            cout<<endl;

    }



    return 0;
}
