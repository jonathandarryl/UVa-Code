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
typedef pair<int,ii> pii;
#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define scan() scanf("%d",&tc);
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
int main(void){
    //freopen("in.txt","r",stdin);
    int tc, S, P;
    scanf("%d",&tc);
    TC(){
        vector< pair<double, ii> > EdgeList;
        EdgeList.clear();
        int x[501],y[501];
        scanf("%d %d",&S,&P);
        for(int i=0;i<P;i++){
            scanf("%d %d",&x[i],&y[i]);
        }
        for(int i=0;i<P;i++)
            for(int j=i+1;j<P;j++)
                EdgeList.push_back(make_pair(hypot((double)(x[i]-x[j]),(double)y[i]-y[j]),ii(i,j)));
        sort(EdgeList.begin(), EdgeList.end());
        //for(int i=0;i<EdgeList.size();i++)
            //printf("%lf %d %d\n",EdgeList[i].first, EdgeList[i].second.first,EdgeList[i].second.second);
        double mst_cost = 0;
        UnionFind UF(P);                     // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
            //printf("%lf %d\n",mst_cost,UF.numDisjointSets());
            if(UF.numDisjointSets() == S) break;
            pair<double, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
                mst_cost = front.first;                // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second);    // link them
        } }                       // note: the runtime cost of UFDS is very light
        printf("%.2lf\n",mst_cost);
    }
    return 0;
}
