#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    double test;
    int cow, car, show;
    while(scanf("%d %d %d",&cow,&car,&show) == 3){
        test = (double)cow/(cow+car)*(double)car/(cow+car-show-1) + (double)car/(car+cow)*(double)(car-1)/(cow+car-show-1);
        printf("%.5lf\n",test);
    }
    return 0;
}
