#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    double test;
    int room;

    while(scanf("%d %lf",&room,&test)==2){
        test+=room*(room+1)/2.0+1;
        printf("%.0lf\n",floor((-1+pow(1+4*2*test,1/2.0))/2));
    }
    return 0;
}
