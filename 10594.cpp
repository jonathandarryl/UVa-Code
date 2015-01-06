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
#define TC() while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

//const L INF = numeric_limits<L>::max() / 4;
L target;
struct MinCostMaxFlow {
  int N;
  VVL cap, flow, cost;
  VI found;
  VL dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) :
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, L cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, L cost, int dir) {
    L val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min(cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INF);
    fill(width.begin(), width.end(), 0);
    dist[s] = 0;
    width[s] = INF;

    while (s != -1) {
      int best = -1;
      found[s] = true;
      for (int k = 0; k < N; k++) {
        if (found[k]) continue;
        Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
        Relax(s, k, flow[k][s], -cost[k][s], -1);
        if (best == -1 || dist[k] < dist[best]) best = k;
      }
      s = best;
    }

    for (int k = 0; k < N; k++)
      pi[k] = min(pi[k] + dist[k], (long long int)INF);
    return width[t];
  }

  pair<L, L> GetMaxFlow(int s, int t) {
    L totflow = 0, totcost = 0;
    //printf("tes\n");
    while (L amt = Dijkstra(s, t)) {

        //printf("AMT: ");


    //L totflowt = totflow;
        amt = min (amt, target);
      totflow += amt;
      target -= amt;

      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
      //printf("totcost: ");
      //cout<<totcost<<endl;
        if(target == 0) break;
    }
    //printf("lgsg keluar\n");
    return make_pair(totflow, totcost);
  }
};

int main(void){
    //freopen("in.txt","r",stdin);
    int N, D;
    int fr, to, cost;
    map<ii,int> mapper;
    while(scanf("%d %d",&N,&D)!=EOF){
        MinCostMaxFlow x = MinCostMaxFlow(N);
        mapper.clear();
        for(int i=0;i<D;i++){
            scanf("%d %d %d",&fr,&to,&cost);
            mapper[ii(fr-1,to-1)] = cost;
            mapper[ii(to-1,fr-1)] = cost;
        }
        int capacity;
        scanf("%lld %d",&target,&capacity);
        for(map<ii,int>::iterator it = mapper.begin();it!=mapper.end();it++){
            x.AddEdge(it->first.first,it->first.second,capacity,it->second);
        }
        pair<L,L> y = x.GetMaxFlow(0,N-1);
        if(target == 0){
            printf("%lld\n",y.second);
        }
        else printf("Impossible.\n");
    }
    return 0;
}
