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

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;

struct MinCostMaxFlow {
  int N;
  vector<VD> cost;
  VVL cap, flow;
  VI found;
  VD dist, pi, width;
  VPII dad;

  MinCostMaxFlow(int N) :
    N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VD(N)),
    found(N), dist(N), pi(N), width(N), dad(N) {}

  void AddEdge(int from, int to, L cap, double cost) {
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
  }

  void Relax(int s, int k, L cap, double cost, int dir) {
    double val = dist[s] + pi[s] - pi[k] + cost;
    if (cap && val < dist[k]) {
      dist[k] = val;
      dad[k] = make_pair(s, dir);
      width[k] = min((double)cap, width[s]);
    }
  }

  L Dijkstra(int s, int t) {
    fill(found.begin(), found.end(), false);
    fill(dist.begin(), dist.end(), INFLL);
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
      pi[k] = min(pi[k] + dist[k], (double)INFLL);
    return width[t];
  }

  pair<L, double> GetMaxFlow(int s, int t) {
    L totflow = 0; double totcost = 0;
    while (L amt = Dijkstra(s, t)) {
      totflow += amt;
      for (int x = t; x != s; x = dad[x].first) {
        if (dad[x].second == 1) {
          flow[dad[x].first][x] += amt;
          totcost += amt * cost[dad[x].first][x];
        } else {
          flow[x][dad[x].first] -= amt;
          totcost -= amt * cost[x][dad[x].first];
        }
      }
    }
    return make_pair(totflow, totcost);
  }
};
int main(void){
    //freopen("in.txt","r",stdin);
    int n,m;
    //MinCostMaxFlow mcmf;
    while(scanf("%d %d",&n,&m),(n||m)){
        MinCostMaxFlow mcmf = MinCostMaxFlow(n+m+2);
        FOR(i,n){
            mcmf.AddEdge(m+1+i,n+m+1,1,0);
        }
        FOR(i,m){
            mcmf.AddEdge(0,i+1,1,0);
        }
        double cost;
        FOR(i,n){
            FOR(j,m){
                scanf("%lf",&cost);
                mcmf.AddEdge(j+1,i+m+1,1,cost);
             //   mcmf.AddEdge(2+j+n,i+2,1,cost);
            }
        }
        pair<L,double> res = mcmf.GetMaxFlow(0,n+m+1);
        printf("%.2lf\n",res.second/n + 1e-6);
    }
    return 0;
}
