#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int test,student,score[100001],max, temp, min[100001];
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&student);
        max = -10000000;
        for(int j=0;j<student;j++)
            scanf("%d",&score[j]);
        min[student-1]=score[student-1];
        for(int j=student-2;j>0;j--)
            if(score[j]<min[j+1])
                min[j]=score[j];
            else
                min[j]=min[j+1];
        for(int j=0;j<student-1;j++)
            if(max<score[j]-min[j+1])
                max = score[j]-min[j+1];
        printf("%d\n",max);
    }
    return 0;
}
