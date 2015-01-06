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

map<int, int> mapper;
vector<vii> AdjList;

int main(void){
    int a,in,b,num,Q,counter,from,to,casecounter=1,layer;
    while(scanf("%d",&a)==1){
        counter = 0;
        mapper.clear();
        AdjList.assign(20,vii());
        for(int i=0;i<a;i++){
            scanf("%d",&b);
            if (mapper.find(1) == mapper.end()) { // mapping trick
              mapper[1] = counter++;
            }
            if (mapper.find(b) == mapper.end()) {
                  mapper[b] = counter++;
            }
            AdjList[mapper[1]].push_back(ii(mapper[b], 0));
            AdjList[mapper[b]].push_back(ii(mapper[1], 0));
        }
        for(int i=2;i<20;i++){
            scanf("%d",&in);
            for(int j=0;j<in;j++){
                scanf("%d",&b);
                if(mapper.find(i)==mapper.end()){
                    mapper[i]=counter++;

                }
                if (mapper.find(b) == mapper.end()) {
                  mapper[b] = counter++;

                }
                AdjList[mapper[i]].push_back(ii(mapper[b], 0));
                AdjList[mapper[b]].push_back(ii(mapper[i], 0));
            }
        }
        map<int,int> dist;
        scanf("%d",&Q);
        int s,x;
        printf("Test Set #%d\n",casecounter++);
        for(int i=0;i<Q;i++){
            dist.clear();
            scanf("%d %d",&from,&to);
            s = mapper[from];
            x = mapper[to];
            dist[s]=0;
            queue<int> q; q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];
                    if (!dist.count(v.first)) {
                        dist[v.first] = dist[u] + 1;
                        //printf("%d%d\n",dist[to],dist[x]);
                        q.push(v.first);
                    }
                } }
            printf("%2d to %2d: %d\n",from,to,dist[x]);
        }
        printf("\n");
    }
}
