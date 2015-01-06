#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int jack[10001];
    int in;
    long long max,temp;;
    while(scanf("%d",&in) && in){
        int input;
        temp = 0;
        max = -1;
        for(int i=0;i<in;i++){
            cin>>input;
            temp+=input;
            if(temp<0)
                temp = 0;
            if(temp>max)
                max = temp;
        }
        if(max>0)
            printf("The maximum winning streak is %lld.\n",max);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
