#include<stdio.h>

int main(void){
    int N;
    while(scanf("%d",&N) && N){
        printf("f91(%d) = ",N);
        if(N<=100)
            N = 91;
        else
            N-=10;
        printf("%d\n",N);
    }
    return 0;
}
