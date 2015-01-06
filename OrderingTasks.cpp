#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii AdjList;
vector<int> topoSort;
int visited[101];
void dfs(int x){
    visited[x] = 1;
    for(int i=0;i<AdjList[x].size();i++){
        int j = AdjList[x][i];
        if(!visited[j])
            dfs(j);
    }
    topoSort.push_back(x);
}

int main(void){
    int n,m,from,to;
    while(cin>>n>>m && (n||m)){
        topoSort.clear();
        AdjList.assign(n+1,vi());
        for(int i=1;i<=n;i++)
            visited[i] = 0;
        for(int i=0;i<m;i++){
            cin>>from>>to;
            AdjList[from].push_back(to);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        for(int i=topoSort.size()-1;i>=0;i--)
            cout<<topoSort[i]<<" ";
        cout<<endl;
        //cout<<topoSort[0]<<endl;
    }
    return 0;
}
