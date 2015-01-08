#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
map<unsigned long long, long long> mapper;
unsigned long long func(unsigned long long x){

    if(mapper.find(x)!=mapper.end())
        return mapper[x];
    if(!(x%2))
        return mapper[x] = func(x/2) + 1;
    return mapper[x] = func(3*x + 1) + 1;
}

int main(void){

    mapper.clear();
    long long min;
    long long x,y,minnum;
    mapper[1] = 1;
    while(cin>>x>>y){
        minnum = -1;
        for(long long i=x;i<=y;i++){
            if(mapper.find(i)==mapper.end())
                func(i);
            if(minnum<mapper[i]){
                minnum = mapper[i];
            }

        }
        cout<<x<<" "<<y<<" "<<minnum<<endl;
    }
    return 0;
}

