#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(void){
    double nephew, CD;
    while(cin>>nephew>>CD){
        if(nephew == 0 && CD == 0)
            return 0;
        printf("%.0lf\n",pow(nephew,CD));
    }
    return 0;
}
