#include<iostream>
#include<stdio.h>
#define INF 1000000
using namespace std;

int main(void){
    int graph[102][102];
    int test;
    cin>>test;
    for(int z=1;z<=test;z++){
        int edge,vertice;
        cin>>edge>>vertice;
        for(int i=0;i<edge;i++)
            for(int j=0;j<edge;j++){
                if(i!=j)
                    graph[i][j] = INF;
                else
                    graph[i][j] = 0;
            }
        int x,y;
        for(int i=0;i<vertice;i++){
            cin>>x>>y;
            graph[x][y] = graph[y][x] = 1;
        }
        int start,end;
        cin>>start>>end;
        printf("Case %d: ",z);
        if(edge == 1)
            cout<<0<<endl;
        else if(edge == 2 && start != end)
            cout<<1<<endl;
        else if(edge == 2)
            cout<<2<<endl;
        else{
            for(int k=0;k<edge;k++)
                for(int i=0;i<edge;i++)
                    for(int j=0;j<edge;j++)
                        graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            int maxi = graph[start][end];
            for(int i=0;i<edge;i++)
                if(i!=start && i!=end){
                    maxi = max(maxi,graph[start][i] + graph[i][end]);
                }
            cout<<maxi<<endl;


        }
    }
    return 0;
}
