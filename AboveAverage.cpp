#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int score[1000];
    int test, n, counter;
    double sum, percentage;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>n;
        sum = 0;
        counter = 0;
        for(int j=0;j<n;j++){
            cin>>score[j];
            sum+=score[j];
        }
        sum/=n;
        for(int j=0;j<n;j++){
            if(score[j]>sum)
                counter++;
        }

        percentage = (double)counter/n * 100;
        printf("%.3lf%%\n",percentage);

    }
    return 0;
}
