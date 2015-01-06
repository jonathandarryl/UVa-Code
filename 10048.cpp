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

vector<vii> AdjList;
int fr, to, cost;

int main(void){
    //freopen("in.txt","r",stdin);
    int c,s,q, casecounter = 1;
    int AdjMat[101][101];
    bool first = true;
    while(scanf("%d %d %d",&c,&s,&q), (c||s||q)){
        if(!first) printf("\n");
        first = false;
       for(int i=0;i<c;i++)
        for(int j=0;j<c;j++)
            AdjMat[i][j] = AdjMat[j][i] = INF;
       for(int i=0;i<s;i++){
            scanf("%d %d %d",&fr,&to,&cost);
            AdjMat[fr-1][to-1] = AdjMat[to-1][fr-1] = cost;
       }
       for(int k=0;k<c;k++)
        for(int i=0;i<c;i++)
            for(int j=0;j<c;j++)
                AdjMat[i][j] = min(AdjMat[i][j], max(AdjMat[i][k], AdjMat[k][j]));
        printf("Case #%d\n",casecounter++);
        for(int i=0;i<q;i++){
            scanf("%d %d",&fr,&to);
            fr--,to--;
            if(AdjMat[fr][to] == INF)printf("no path\n");
            else printf("%d\n",AdjMat[fr][to]);
        }
    }
    return 0;
}
