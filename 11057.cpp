#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void){
    int numinput,searched;
    int num[10001],hi,lo;
    while(scanf("%d",&numinput)==1){
        for(int i=0;i<numinput;i++)
            scanf("%d",&num[i]);
        scanf("%d",&searched);
        sort(num,num+numinput);
        for(int i=0;num[i]<=searched/2;i++){
            if(num[i]==searched/2 && num[i+1]==searched/2){
                hi = num[i];
                lo = num[i];
                break;
            }
            if(binary_search(num,num+numinput,searched-num[i])){
                hi = searched-num[i];
                lo = num[i];
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",lo,hi);
    }
    return 0;
}
