#include<map>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long fib[100];
int main(void){
    map<int,char> fibzz;
    long long temp = 2147483647;
    int counter = 2, counter1;
    fib[0]=1;
    fib[1]=2;
    string str;

    int res[100],input,test;
    for(int i=2;i<=45;i++)
        fib[i]=fib[i-1]+fib[i-2];
    cin>>input;
    for(int i=0;i<input;i++){
        fibzz.clear();
        cin>>test;
        for(int j=0;j<test;j++){
            cin>>res[j];
        }
        getline(cin,str);
        getline(cin,str);
        counter = counter1 = 0;
        while(counter<test){
            if(str.at(counter1)>='A' && str.at(counter1)<='Z'){
                fibzz[res[counter]]=str.at(counter1);
                counter++;
                counter1++;
            }
            else
                counter1++;
        }
        for(int i=0;i<test;i++){
            if(fibzz.find(fib[i])==fibzz.end()){
                cout<<" ";
                test++;
            }
            else
                cout<<fibzz[fib[i]];
        }
        cout<<endl;
    }
    return 0;
}
