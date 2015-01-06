#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(void){
    map<int,int> in;
    int N,K,input;
    map<int,int>::iterator it;
    long long sum;
    while(scanf("%d %d",&N,&K) && N && K){
        in.clear();
        if(N==K){
            sum = 0;
            for(int i=0;i<N;i++){
                scanf("%d",&input);
                sum+=input;
            }
            printf("%lld\n",sum);
        }
        else{
            for(int i=0;i<N;i++){
                scanf("%d",&input);
                in[input]++;
            }
            sum = 0;
            it = in.end();
            it--;
            for(int i=0;i<K;i++){
                sum+=it->first;
                it->second--;
                if(!it->second)
                    it--;
            }
            printf("%lld\n",sum);
        }


    }

}
