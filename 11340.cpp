#include<iostream>
#include<string>
#include<stdio.h>
#include<map>
using namespace std;

int main(void){
    string test;
    char pricez;
    map<char,int> price;
    int testcase, howmany, line, value;
    double sumz;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>howmany;
        sumz = 0;
        price.clear();
        getline(cin,test);
        for(int j=0;j<howmany;j++){
            getline(cin,test);
            pricez = test.at(0);
            value = 0;
            for(int k=2;k<test.length();k++){
                value*=10;
                value+=test.at(k)-'0';
            }
            price[pricez] = value;
        }
        cin>>line;
        getline(cin,test);
        for(int j=0;j<line;j++){
            getline(cin,test);
            for(int k=0;k<test.length();k++){
                if(price.find(test.at(k))!=price.end())
                    sumz+=price[test.at(k)];
            }
        }
        printf("%.2lf$",sumz/100);
        cout<<endl;
    }
    return 0;
}
