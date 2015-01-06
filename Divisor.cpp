#include<iostream>
#include<stdio.h>
#include<map>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(void){
    map<int,int> mapper;
    mapper.clear();
    int TC,low,high,mindiv,minnum;
    scanf("%d",&TC);
    while(TC--){
        minnum = -1;
        scanf("%d %d",&low,&high);
        mindiv = 0;

        for(int i=low;i<=high;i++){
            int x = (int)floor(sqrt(i));
            int sum = 2;
            for(int j=2;j<=x;j++){
                if(!(i%j)){
                    sum+=2;
                    if(j==x && x*x == i)
                        sum--;
                }

            }
            if(i==1)
                sum--;
            if(mindiv<sum){
                mindiv = sum;
                minnum = i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",low,high,minnum,mindiv);
    }
    return 0;
}
