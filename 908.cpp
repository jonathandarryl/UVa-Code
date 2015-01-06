#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC(tc) while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))

vi taken;
priority_queue<ii> pq;
vector<vii> AdjList;
void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }

int main(void){
    //freopen("in.txt","r",stdin);
    int N, mst_cost;
    bool first = true;
    //priority_queue<ii>pq;
    while(scanf("%d",&N)!=EOF){
        if(!first)printf("\n");
        first = false;
        int a,b,c,K;
        AdjList.assign(N,vii());
        for(int i=0;i<N-1;i++){
            scanf("%d %d %d",&a,&b,&c);
            AdjList[a-1].push_back(ii(b-1,c));
            AdjList[b-1].push_back(ii(a-1,c));
        }
        int u,w;
        taken.assign(N, 0);                // no vertex is taken at the beginning
        process(0);   // take vertex 0 and process all edges incident to vertex 0
        mst_cost = 0;
        while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            u = -front.second, w = -front.first;  // negate the id and weight again
            if (!taken[u])                 // we have not connected this vertex yet
                mst_cost += w, process(u); // take u, process all edges incident to u
        }
        printf("%d\n",mst_cost);
        AdjList.assign(N,vii());
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d %d %d",&a,&b,&c);
            AdjList[a-1].push_back(ii(b-1,c));
            AdjList[b-1].push_back(ii(a-1,c));
        }
        scanf("%d",&K);
        for(int i=0;i<K;i++){
            scanf("%d %d %d",&a,&b,&c);
            AdjList[a-1].push_back(ii(b-1,c));
            AdjList[b-1].push_back(ii(a-1,c));
        }
        taken.assign(N, 0);                // no vertex is taken at the beginning
        process(0);   // take vertex 0 and process all edges incident to vertex 0
        mst_cost = 0;
        while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            u = -front.second, w = -front.first;  // negate the id and weight again
            if (!taken[u])                 // we have not connected this vertex yet
                mst_cost += w, process(u); // take u, process all edges incident to u
        }
        printf("%d\n",mst_cost);
    }

    return 0;
}
