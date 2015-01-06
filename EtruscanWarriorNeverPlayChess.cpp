#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    double test;
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%lf",&test);
        printf("%.0lf\n",floor((-1+pow(1+4*2*test,1/2.0))/2));
    }
    return 0;
}
