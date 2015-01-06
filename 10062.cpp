#include<map>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct{
    int ascii;
    int freq;
}iden;

bool sort_cmp(iden a, iden b){
    if(a.freq!=b.freq)
        return a.freq<b.freq;
    else
        return a.ascii>b.ascii;
}

int main(void){
    map<char,int> store;
    string input;
    iden id[250];
    int counter;
    bool first = true;
    while(getline(cin,input)){
        store.clear();
        counter = 0;
        if(first)
            first = false;
        else
            cout<<endl;
        for(int i=0;i<input.length();i++)
            store[input.at(i)]++;
        for(map<char,int>::iterator it=store.begin();it!=store.end();it++){
            id[counter].ascii = (int)it->first;
            id[counter].freq = it->second;
            counter++;
        }
        sort(id,id+counter,sort_cmp);
        for(int i=0;i<counter;i++)
            cout<<id[i].ascii<<" "<<id[i].freq<<endl;
    }
    return 0;
}
