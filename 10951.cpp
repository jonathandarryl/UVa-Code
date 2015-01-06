#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

map<int, int> mapper;
vector<vii> AdjList;
map<int,int> dist;
int main(void){
    int test, P, D,counter,a,b;
    scanf("%d",&test);
    while(test--){
        counter = 0;
        scanf("%d %d",&P,&D);
        mapper.clear();
        AdjList.assign(P,vii());
        for(int i=0;i<D;i++){
            scanf("%d %d",&a,&b);
            if (mapper.find(b) == mapper.end())
                  mapper[b] = counter++;
            if(mapper.find(a) == mapper.end())
                mapper[a] = counter++;
            AdjList[mapper[a]].push_back(ii(mapper[b], 0));
            AdjList[mapper[b]].push_back(ii(mapper[a], 0));
        }
        dist.clear();
        queue<int> q;q.push(mapper[0]);
        dist[mapper[0]] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (!dist.count(v.first)) {
                    dist[v.first] = dist[u] + 1;
                    //printf("%d%d\n",dist[to],dist[x]);
                    q.push(v.first);
                }
            }
        }


        for(int i=1;i<P;i++){
            printf("%d\n",dist[mapper[i]]-1);
        }
        if(test)
            printf("\n");
    }
    return 0;
}
