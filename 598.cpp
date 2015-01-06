#include<iostream>
#include<sstream>
#include<stdio.h>
#include<vector>
using namespace std;
int counter;
string news[13];

void comb(int now, int count, int maxz, vector<string> name){
    if(count==maxz){
        for(int i=0;i<maxz-1;i++)
            cout<<name.at(i)<<", ";
        cout<<name.at(maxz-1)<<endl;
        name.clear();
        return;
    }
    else{
        for(int i=now;i<counter-1;i++){
            name.push_back(news[i]);
            comb(i+1,count+1,maxz,name);
            name.pop_back();
        }
    }
    return;
}
int main(void){
    string in;
    vector<string> name;
    int test, low, high, cond;
    cin>>test;
    getchar();
    getchar();
    for(int j=0;j<test;j++){
        name.clear();
        getline(cin,in);
        if(in.length()>2){
            stringstream(in)>>low>>high;
                cond = 1;
        }
        else if(in.at(0)=='*'){
            cond = 2;
        }
        else{
            stringstream(in)>>low;
            cond = 3;
        }
        counter = 0;
        while(getline(cin,news[counter++])){
            if(news[counter-1].empty())
                break;
        }

        if(cond==1){
            for(int i=low;i<=high;i++){
                name.clear();
                cout<<"Size "<<i<<endl;
                comb(0,0,i,name);
                    cout<<endl;
            }
        }
        else if(cond==2){
            for(int i=1;i<counter;i++){
                name.clear();
                cout<<"Size "<<i<<endl;
                comb(0,0,i,name);
                cout<<endl;
            }
        }
        else if(cond==3){
            name.clear();
            cout<<"Size "<<low<<endl;
            comb(0,0,low,name);
            cout<<endl;
        }
        if(j!=test-1)
            cout<<endl;
    }
    return 0;
}
