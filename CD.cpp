#include<map>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int N,M, num;
    int counter;
    map<int,int> cd;
    while(scanf("%d %d",&N,&M)){
        if(N == 0 && M == 0)
            return 0;
        cd.clear();
        counter = 0;
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            cd[num]++;
        }
        for(int i=0;i<M;i++){
            scanf("%d",&num);
            if(cd[num])
                counter++;
        }
        printf("%d\n",counter);

    }

    return 0;
}
