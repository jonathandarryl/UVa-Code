#include<stdio.h>

int main(void){
    int input, counter;
    long long number;
    while(scanf("%d",&input)==1){
        counter = 1;
        number = 1;
        while(true){
            if(number%input==0){
                printf("%d\n",counter);
                break;
            }
            number = number*10 + 1;
            number = number%input;
            counter++;
        }
    }
    return 0;
}
