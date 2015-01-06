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

vi taken;
priority_queue<ii>pq;
vector<vii> AdjList;
void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }
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

int main(void){
    vector< pair<int, ii> > takenz;
    int casecounter = 1;
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    TC(){
        takenz.clear();
        vector< pair<int, ii> > EdgeList;
        int V,u,w;
        int num;
        scanf("%d",&V);
        //AdjList.assign(V,vii());
        for(int i=0;i<V;i++){
            for(int j=0;j<V-1;j++){
                scanf("%d,",&num);
                //printf("%d %d %d\n",i,j,num);
                if(num)
                EdgeList.push_back(make_pair(num,ii(i,j)));
            }
            scanf("%d",&num);
            if(num)
            EdgeList.push_back(make_pair(num,ii(i,V-1)));
        }

         //weight, ii(u,v)
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                  // note: pair object has built-in comparison function
        /*for(int i=0;i<EdgeList.size();i++)
            printf("%d %d %d\n",EdgeList[i].first,EdgeList[i].second.first,EdgeList[i].second.second);
        */
        int mst_cost = 0;
        UnionFind UF(V);                     // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
            pair<int, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
                mst_cost += front.first;                // add the weight of e to MST
                takenz.push_back(front);
                UF.unionSet(front.second.first, front.second.second);    // link them
            }
        }                       // note: the runtime cost of UFDS is very light
        sort(takenz.begin(),takenz.end());
        printf("Case %d:\n",casecounter++);
        for(int i=0;i<takenz.size();i++){
            printf("%c-%c %d\n",'A'+takenz[i].second.first,'A'+takenz[i].second.second,takenz[i].first);
        }
    }

    return 0;
}
