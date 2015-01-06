#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;

int main(void){
    vector<int> x1,x3,y1,y3;
    int length,length2,mintemp,temp,ans,dim;
    char num[1000][1000];

    while(scanf("%d",&dim)==1){
        getchar();
        ans = 0;
        x1.clear();
        x3.clear();
        y1.clear();
        y3.clear();
        for(int i=0;i<dim;i++)
            gets(num[i]);
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++){
                if(num[i][j]=='1'){
                    x1.push_back(i);
                    y1.push_back(j);
                }
                else if(num[i][j]=='3'){
                    x3.push_back(i);
                    y3.push_back(j);
                }
            }
        length = x1.size();
        length2 = x3.size();
        for(int i=0;i<length;i++){
            mintemp = 1000;
            for(int j=0;j<length2;j++){
                temp = abs(x1.at(i)-x3.at(j))+abs(y1.at(i)-y3.at(j));
                if(temp<mintemp)
                    mintemp = temp;
            }
            if(ans<mintemp)
                ans = mintemp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
