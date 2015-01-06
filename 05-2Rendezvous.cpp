#include<iostream>
#include<stdio.h>
#include<string.h>
#define INF 1000000
using namespace std;

int main(void){
    int member, route,casecounter = 1;
    int graph[24][24];
    string name[24];
    while(cin>>member>>route && member){
        for(int i=1;i<=member;i++)
            cin>>name[i];
        for(int i=1;i<=member;i++)
            for(int j=1;j<=member;j++){
                if(i!=j)
                    graph[i][j] = INF;
                else
                    graph[i][j] = 0;
            }
        int x,y,dis;
        for(int i=0;i<route;i++){
            cin>>x>>y>>dis;
            graph[x][y] = graph[y][x] = dis;
        }
        for(int k=1;k<=member;k++)
            for(int i=1;i<=member;i++)
                for(int j=1;j<=member;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        int min[25],temp,res;

        for(int i=1;i<=member;i++){
            min[i] = 0;
            for(int j=1;j<=member;j++){
                min[i] += graph[i][j];
                //cout<<graph[i][j]<<" ";
            }
            //cout<<endl;
        }
        temp = INF;
        for(int i=1;i<=member;i++){
            if(temp>min[i]){
                temp = min[i];
                res = i;
            }
        }
        cout<<"Case #"<<casecounter++<<" : "<<name[res]<<endl;
    }
    return 0;
}
