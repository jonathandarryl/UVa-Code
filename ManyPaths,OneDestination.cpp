#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
vii AdjList;
vi topoSort;
int dfs[100000];
void dfsnum(int vtx){
    dfs[vtx] = 1;
    for(int i=0;i<(int)AdjList[vtx].size();i++){
        int v = AdjList[vtx][i];
        if(dfs[v] == 0)
            dfsnum(v);
    }
    topoSort.push_back(vtx);
}

int main(void){
    int numvertex = 0,numneighbor,x,total;
    while(cin>>numvertex){
        topoSort.clear();
        AdjList(numvertex,vii());
        for(int i=0;i<numvertex;i++){
            cin>>numneighbor;
            for(int j=0;j<numneighbor;j++){
                cin>>x;
                AdjList[i].push_back(x);
            }
        }
        for(int i=0;i<numvertex;i++)
            dfs[i] = 0;
        for(int i=0;i<numvertex;i++)
            if(dfs[i]==0)
                dfsnum(i);
        reverse(topoSort.begin(),topoSort.end());
        int ways[numvertex]={};
        ways[0] = 1;
        for(int i=0;i<topoSort.size();i++){
            int x = topoSort[i];
            for(int j=0;j<(int)AdjList[x].size();j++)
                ways[AdjList[x][j]]+=ways[x];
        }
        total = 0;
        for(int j=0;j<topoSort.size();j++)
            if((int)AdjList[j].size() == 0){
                total+=ways[AdjList[j]];
            }
        cout<<total<<endl;
    }
    return 0;
}
