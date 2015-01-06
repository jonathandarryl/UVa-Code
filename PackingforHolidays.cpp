#include<stdio.h>

int main(void){
    int test, h,w,l;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        scanf("%d %d %d",&h,&w,&l);
        printf("Case %d: ",i);
        if(h<=20 && w<=20 && l<=20)
            printf("good\n");
        else
            printf("bad\n");
    }
    return 0;
}
