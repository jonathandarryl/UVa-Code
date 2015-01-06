#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>

using namespace std;

map<int,int>mapper;
int AdjMat[102][102];
int main(void){
    int a,b,counter,casecounter=1;
    while(true){

        for(int i=0;i<102;i++)
            for(int j=0;j<102;j++){
                if(i!=j)
                    AdjMat[i][j] = 10000000;
                else
                    AdjMat[i][j] = 0;
            }
        scanf("%d %d",&a,&b);
        if(!a && !b)
            return 0;
        counter = 0;
        mapper.clear();
        if(mapper.find(a)==mapper.end())
            mapper[a]=counter++;
        if(mapper.find(b)==mapper.end())
            mapper[b]=counter++;
        AdjMat[mapper[a]][mapper[b]] = 1;
        while(scanf("%d %d",&a,&b) && a && b){
            if(mapper.find(a)==mapper.end())
            mapper[a]=counter++;
            if(mapper.find(b)==mapper.end())
                mapper[b]=counter++;
            AdjMat[mapper[a]][mapper[b]] = 1;
        }
        for(int k=0;k<counter;k++)
            for(int i=0;i<counter;i++)
                for(int j=0;j<counter;j++)
                    AdjMat[i][j] = min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
        double total = 0,div;
        for(int i=0;i<counter;i++){
            for(int j=0;j<counter;j++)
                total+=AdjMat[i][j];
        }
        div = counter*counter - counter;

        printf("Case %d: average length between pages = %.3lf clicks\n",casecounter++,total/div);


    }
    return 0;
}
