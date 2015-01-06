#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

map<int,int> cost;
long long ans;
void convert(int num, int base){
    if(num==0)
        return;
    ans+=cost[num%base];
    convert(num/base,base);
}

int main(void){
    int test,num,cases;
    vector<int> cheap;
    scanf("%d",&test);
    for(int i=1;i<=test;i++){
        printf("Case %d:\n",i);
        for(int j=0;j<36;j++)
            scanf("%d",&cost[j]);
        scanf("%d",&cases);
        for(int k=0;k<cases;k++){
            scanf("%d",&num);
            printf("Cheapest base(s) for number %d:",num);
            cheap.clear();
            long long min=2147483647;
            if(num==1||num==0){
                for(int j=2;j<=36;j++)
                    printf(" %d",j);
                printf("\n");
            }
            else{
                for(int j=2;j<=36;j++){
                    ans = 0;

                    convert(num,j);
                    if(ans<min){
                        min = ans;
                        cheap.clear();
                        cheap.push_back(j);
                    }
                    else if(ans == min)
                        cheap.push_back(j);
                }
                for(vector<int>::iterator it = cheap.begin();it!=cheap.end();it++)
                    printf(" %d",*it);
                printf("\n");
            }
        }
        if(i!=test)
            printf("\n");
    }
    return 0;
}
