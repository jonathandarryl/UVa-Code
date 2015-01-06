#include<map>
#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;

int main(void){
    string dum1,dum2, line;
    map<string,string> dict;
    while(true){
        getline(cin, line);
        istringstream is(line);
        string s1, s2;
        if (!(is >> s1 >> s2)) break;


        dict[s2] = s1;
    }
    while(getline(cin,dum1)){
        if(dict.find(dum1)==dict.end())
            cout<<"eh"<<endl;
        else
            cout<<dict.find(dum1)->second<<endl;
    }
    return 0;
}
