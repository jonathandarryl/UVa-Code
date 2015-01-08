#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

bool isSubset(string a, string b){
    if(a.length()<b.length() && b.length()%a.length()==0)
        for(int j=0;j<a.length();j++)
        for(int i=j;i<b.length();i+=a.length()){
            if(b.at(i)!=a.at(j))
                return false;
        return true;
    }
    else if(a.length()>b.length() && a.length()%b.length()==0){
        for(int j=0;j<b.length();j++)
            for(int i=j;i<a.length();i+=b.length()){
                if(a.at(i)!=b.at(j))
                    return false;
            return true;
            }
    }
    else return false;
}

bool sort_comp(string a, string b){
    int counta, countb;
    if(a==b||(a.length()!=b.length() && isSubset(a,b)))    return a.at(0)>b.at(0);
    counta = countb = 0;
    while(a.at(counta)==b.at(countb)){
        counta++;
        countb++;
        if(counta==a.length())
            counta=0;
        if(countb==b.length())
            countb=0;
    }
    return a.at(counta)>b.at(countb);
}



int main(void){
    int input;
    string in[100000];
    while(cin>>input && input){
        for(int i=0;i<input;i++)
            cin>>in[i];
        stable_sort(in,in+input,sort_comp);
        for(int i=0;i<input;i++)
            cout<<in[i];
        cout<<endl;
    }
    return 0;
}
