#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int input;
    int counter;
    int money[1001];
    int day;
    scanf("%d",&input);
    for(int i=0;i<input;i++){
        counter = 0;
        scanf("%d",&day);
        scanf("%d",&money[0]);
        for(int j=1;j<day;j++){
            scanf("%d",&money[j]);
            for(int k=0;k<j;k++){
                if(money[j]>=money[k])
                    counter++;
            }
        }
        printf("%d\n",counter);

    }

}
