#include<set>
#include<map>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    set<int> myset;
    map<int,int> maps;
    map<int,int>::iterator it;
    int input,test, in;
    long long total;
    while(scanf("%d",&input) && input){
        total = 0;
        maps.clear();
        for(int i=0;i<input;i++){
            scanf("%d",&test);
            for(int j=0;j<test;j++){
                scanf("%d",&in);
                maps[in]++;
            }
            it =maps.end();
            it--;
            total+=it->first;
            it->second--;
            if(it->second==0)
                maps.erase(it);
            it = maps.begin();
            total-=it->first;
           it->second--;
            if(it->second==0)
                maps.erase(it);
        }
        printf("%lld\n",total);
    }


    return 0;
}
