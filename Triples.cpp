#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main(void){
  int N;
  long long num,total;
  map<long long, int> mapper;
  while(scanf("%d",&N)==1){
    mapper.clear();
    for(int i=0;i<N;i++){
      scanf("%lld",&num);
      mapper[num]++;
    }
    total = 0;
    for(map<long long,int>::iterator it=mapper.begin();it!=mapper.end();it++){
        map<long long,int>::iterator it2;
        it2= it;
        it2++;
        total+=it->second*(it->second-1)*mapper[it->first + it->first]/2;
        for(;it2!=mapper.end();it2++){
            total+=it->second*it2->second*mapper[it->first + it2->first];
        }
    }
    printf("%lld\n",total);
  }
  return 0;
}
