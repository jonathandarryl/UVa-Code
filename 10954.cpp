#include<queue>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    priority_queue<int> pq;
    int length;
    int dummy, sum, cost;
    while(scanf("%d",&length) && length){
        for(int i=0;i<length;i++){
            scanf("%d",&dummy);
            dummy*=-1;
            pq.push(dummy);
        }
        sum = 0;
        while(pq.size()>1){
            dummy = -1*pq.top();
            pq.pop();
            dummy+=-1*pq.top();
            pq.pop();
            sum+=dummy;
            dummy*=-1;
            pq.push(dummy);

        }

        printf("%d\n",sum);
        pq.pop();
    }


    return 0;
}
