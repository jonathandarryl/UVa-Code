#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii AdjList;
int visited[201];
int visited2[201];
void dfs(int x, int color){
    visited[x] = color;
    for(int i=0;i<AdjList[x].size();i++){
        int y = AdjList[x][i];
        if(visited[y]==-1)
            dfs(y,(color+1)%2);
    }
}

bool dfscheck(int x){
    bool valid = true;
    int use = visited[x];
    visited2[x] = 1;
    for(int i=0;i<AdjList[x].size();i++){
        int y = AdjList[x][i];
        if(visited[y]==visited[x]) {valid = false; break;}
        if(!visited2[y])
            dfscheck(y);
        }

    return valid;
}

int main(void){

    int num;
    while(cin>>num && num){
        AdjList.assign(num,vi());
        int edge;
        cin>>edge;
        for(int i=0;i<num;i++)
            visited[i] = -1;
        for(int i=0;i<edge;i++){
            int from,to;
            cin>>from>>to;
            AdjList[from].push_back(to);
            AdjList[to].push_back(from);
        }
        dfs(0,1);
        for(int i=0;i<num;i++)
            visited2[i]=0;
        if(dfscheck(0)){
            cout<<"BICOLORABLE."<<endl;
        }
        else
            cout<<"NOT BICOLORABLE."<<endl;
    }

    return 0;
}
