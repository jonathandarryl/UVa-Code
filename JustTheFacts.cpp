#include<stdio.h>

int main(void){
    int result[10000];
    result[0]=result[1]=1;
    int temp=1;
    for(int i=2;i<10000;i++){
        temp*=i;
        while(temp%10==0)
            temp/=10;
        temp%=100000;
        result[i]=temp%10;
    }
    int input;
    while(scanf("%d",&input)==1){
        printf("%5d -> %d\n",input,result[input]);
    }
    return 0;
}
