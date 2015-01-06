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
//typedef pair<int,int> ii;
typedef pair<double,int>ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vi taken;
priority_queue<ii>pq;
vector<vii> AdjList;
void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.second]) pq.push(ii(-v.first, -v.second));
}
}

int main(void){
    //freopen("in.txt","r",stdin);
    int tc,casecounter = 1;
    scanf("%d",&tc);
    TC(){
        int V,threshold;
        double x[200],y[200];
        scanf("%d",&V);
        //UnionFind UF(V);
        AdjList.assign(V,vii());
        for(int i=0;i<V;i++){
            scanf("%lf %lf",&x[i],&y[i]);
        }
        for(int i=0;i<V;i++)
            for(int j=i+1;j<V;j++){
                double dist = hypot(x[i]-x[j],y[i]-y[j]);
                //printf("%lf %d %d\n",dist,i,j);
                AdjList[i].push_back(ii(dist,j));
                AdjList[j].push_back(ii(dist,i));
                /*if(dist <= threshold){
                    if(!UF.isSameSet(i,j)){
                        UF.unionSet(i,j);
                    }
                }*/
            }
       /* for(int i=0;i<AdjList.size();i++)
            for(int j=0;j<AdjList[i].size();j++)
            printf("%lf %d %d\n",AdjList[i][j].first,AdjList[i][j].second,i);
          */
            int u;
            double w;
            taken.assign(V, 0);                // no vertex is taken at the beginning
            process(0);   // take vertex 0 and process all edges incident to vertex 0
            double mst_cost = 0;
            while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken

                ii front = pq.top(); pq.pop();
                u = -front.second, w = -front.first;  // negate the id and weight again
                if (!taken[u]){                 // we have not connected this vertex yet
                    //printf("take: %lf %d\n",w,u);

                    mst_cost += w, process(u);
                }
            }                                        // each edge is in pq only once!
        printf("%.2lf\n",mst_cost);
        if(tc)printf("\n");
    }
    return 0;
}
