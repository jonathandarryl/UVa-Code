#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cmath>
using namespace std;

int low, high, total,fairness, maxppl;
int weight[102];

void compute(int now, int tot){
    if(now==maxppl || tot>=total/2){
        int x = total-tot;
        if(fairness>abs((double)(x-tot))){
            fairness = (int)abs((double)(x-tot));
            if(tot<x){
                low = tot;
                high = x;
            }
            else{
                low = x;
                high = tot;
            }
        }
        return;
    }
    else{
        for(int i=now;i<maxppl;i++){
            compute(i+1, tot+weight[i]);
        }
    }
    return;
}

int main(void){
    int TC;
    scanf("%d",&TC);
    low = high = 0;
    while(TC--){
        scanf("%d",&maxppl);
        total = 0;
        fairness = 100000000;
        for(int i=0;i<maxppl;i++){
            scanf("%d",&weight[i]);
            total+=weight[i];
        }
        compute(0,0);
        printf("%d %d\n",low, high);
        if(TC)
            printf("\n");
    }
}
