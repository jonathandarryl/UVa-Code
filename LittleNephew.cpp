#include<stdio.h>

int main(void){
    int a,b,c,d,e;
    bool first = true;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&e) && (a||b||c||d||e)){

        printf("%lld\n",a*b*c*d*e*d*e);
    }
    return 0;
}
