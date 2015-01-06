#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    int n;
    unsigned long long int result, sample;
    while(true){
        scanf("%d",&n);
        if(n<0)
            break;
        sample = n;
        result = (sample*sample + sample)/2+1;
        cout<<result;
        printf("\n");

    }
    return 0;
}
