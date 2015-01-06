#include<string.h>
#include<map>
#include<iostream>
using namespace std;

int main(void){
    map<char,long long> dict;
    int test, len;
    long long max = 0;
    string in;
    cin>>test;
    getline(cin,in);
    for(int i=0;i<test;i++){
        getline(cin,in);
        len = in.length();
        for(int j=0;j<len;j++){
            if(in.at(j)>='A' && in.at(j)<='Z' || in.at(j)>='a' && in.at(j)<='z')
            dict[toupper(in.at(j))]++;
        }
    }
    while(true){
        max = 0;
        for(map<char,long long>::iterator it = dict.begin();it!=dict.end();it++)
            if(it->second > max)
                max = it->second;
        if(max == 0)
            break;
        for(map<char,long long>:: iterator it = dict.begin();it!=dict.end();it++){
            if(it->second == max){
                cout<<it->first<<" "<<it->second<<endl;
                it->second = 0;
            }
        }
    }
    return 0;
}
