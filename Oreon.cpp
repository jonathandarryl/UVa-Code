#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vi;
typedef vector<vi> vii;

vii AdjList,MST;
vector<int> taken;
priority_queue<pii> pq;

void process(int vtx) {
  taken[vtx] = 1;
  for (int j = 0; j < AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(pii(-v.second, ii(-v.first,-vtx)));
    }
}
int main(void){
    int tc,dist;
    cin>>tc;
    while(tc--){
        int numnode;
        AdjList.assign(numnode,vi());
        MST.assign(numnode,vi());
        for(int i=0;i<numnode;i++){
            for(int j=0;j<numnode-1;j++){
                scanf("%d,",&dist);
                if(dist){
                    AdjList[i].push_back(ii(j,dist));
                }
            }
            scanf("%d",&dist);
            if(dist)
                AdjList[i].push_back(ii(numnode-1,dist));
        }
        taken.assign(numnode, 0);
        process(0);
        int mst_cost = 0;
        int u,w,v;
        while (!pq.empty()) {
          pii front = pq.top(); pq.pop();
          ii x = front.second;
          u = -x.first, w = -front.first, v = -x.second;
          if (!taken[u]){
            MST[u].push_back(ii(w,v));
            process(u);
          }
        }
          printf("MST cost = %d (Prim's)\n", mst_cost);
    }
    return 0;
}
