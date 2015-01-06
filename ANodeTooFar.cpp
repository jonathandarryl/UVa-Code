#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stdio.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

map<int, int> mapper, reverseMapper,lister;
vi p;
vector<vii> AdjList;
int main(void){
    int notreached,casecounter = 1;
    int numpair,g1,g2,a,b,counter;
    int mapped,TTL;
    int s,layer;
    map<int,int> dist;
    while(cin>>numpair && numpair){
        counter = 0;
        AdjList.clear();
        lister.clear();
        AdjList.assign(60,vii());
        mapper.clear();
        reverseMapper.clear();
        for(int i=0;i<numpair;i++){
            scanf("%d %d",&a,&b);
            if (mapper.find(a) == mapper.end()) { // mapping trick
              mapper[a] = counter++;
              reverseMapper[mapper[a]] = a;
            }
            if (mapper.find(b) == mapper.end()) {
                  mapper[b] = counter++;
                  reverseMapper[mapper[b]] = b;
            }
            AdjList[mapper[a]].push_back(ii(mapper[b], 0));
            AdjList[mapper[b]].push_back(ii(mapper[a], 0));
        }
        while(scanf("%d %d",&mapped,&TTL)&& (mapped||TTL)){
            dist.clear();
            notreached = 0;
            p.assign(60,-1);
            s = mapper[mapped];
            dist[s]=0;
            queue<int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                layer = dist[u];
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];
                    if (!dist.count(v.first)) {
                        dist[v.first] = dist[u] + 1;
                        if(dist[v.first]<=TTL)
                            notreached++;
                        p[v.first] = u;
                        q.push(v.first);
                    }  } }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",casecounter++,lister.size()-1-notreached,mapped,TTL);
        }

    }
    return 0;
}
