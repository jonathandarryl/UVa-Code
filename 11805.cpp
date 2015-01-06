#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int test, player, start, pass, land;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        scanf("%d %d %d",&player,&start,&pass);
        land = start+pass;
        land = land%player;
        if(!land)
            land = player;
        printf("Case %d: %d\n",i,land);
    }
    return 0;
}
