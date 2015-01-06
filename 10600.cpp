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
    int tc;
    scanf("%d",&tc);
    TC(){
        int V, R;
        int fr, to, cost;
        vector< pair<int, ii> > MST, EdgeList, Edgetemp;
        scanf("%d %d",&V,&R);
        for(int i=0;i<R;i++){
            scanf("%d %d %d",&fr,&to,&cost);
            EdgeList.push_back(make_pair(cost,ii(fr-1,to-1)));
        }
        sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                      // note: pair object has built-in comparison function

        int mst_cost = 0;
        UnionFind UF(V);                     // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
            pair<int, ii> front = EdgeList[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
                MST.push_back(front);
                mst_cost += front.first;                // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second);    // link them
        } }                       // note: the runtime cost of UFDS is very light
        printf("%d ",mst_cost);
        //printf("EDGELIST:\n");
        //for(int k=0;k<EdgeList.size();k++)
          //      printf("%d %d %d\n",EdgeList[i].first,EdgeList[i].second.first, EdgeList[i].second.second);
        int mst2 = INF;
        for(int i=0;i<MST.size();i++){
            mst_cost = 0;
            for(int j=0;j<EdgeList.size();j++){
                if(!(EdgeList[j].first==MST[i].first && EdgeList[j].second.first == MST[i].second.first && EdgeList[j].second.second == MST[i].second.second)){
                    Edgetemp.push_back(EdgeList[j]);
                }else{
                    Edgetemp.push_back(make_pair(INF,ii(MST[i].second.first,MST[i].second.second)));
                }
            }
           // for(int k=0;k<Edgetemp.size();k++)
             //   printf("%d %d %d\n",Edgetemp[k].first,Edgetemp[k].second.first, Edgetemp[k].second.second);
          //  printf("%d %d\n",Edgetemp.size(), EdgeList.size());
            sort(Edgetemp.begin(),Edgetemp.end());
            UnionFind UF(V);
            for (int i = 0; i < Edgetemp.size(); i++) {                      // for each edge, O(E)
            pair<int, ii> front = Edgetemp[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
                //MST.push_back(front);
                mst_cost += front.first;                // add the weight of e to MST
                UF.unionSet(front.second.first, front.second.second);    // link them
        } }
        mst2 = min(mst2,mst_cost);
        Edgetemp.clear();
        }
        printf("%d\n",mst2);
    }
    return 0;
}
