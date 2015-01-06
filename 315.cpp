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
#include <sstream>
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
#define DFS_WHITE -1
vi dfs_low, dfs_num;       // ARTICULATION POINT/BRIDGE/STRONGLYCONNECTEDCOMPONENTS
vi articulation_vertex;
vi dfs_parent;
vector<vi> AdjList;
int dfsNumberCounter, dfsRoot, rootChildren;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == DFS_WHITE) {                          // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;  // special case, count children of root

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u])              // articulation point
                articulation_vertex[u] = 1;           // store this information first
            if (dfs_low[v] > dfs_num[u])                           // for bridge
                //printf(" Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);       // update dfs_low[u]
        }
        else if (v != dfs_parent[u])       // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);       // update dfs_low[u]
} }


int main(void){
    //freopen("in.txt","r",stdin);
    int n;
    string str;
    vi num;

    while(scanf("%d",&n),n){
        getline(cin,str);
        AdjList.assign(n,vi());
        while(getline(cin,str)){
            num.clear();
            stringstream ss(str);
            int n;
            while(ss>>n){
                num.pb(n-1);
            }
            if(num[0] == -1)break;

            REP(i,1,num.size()){
                AdjList[num[0]].pb(num[i]);
                AdjList[num[i]].pb(num[0]);
            }
        }
        dfsNumberCounter = 0;dfs_num.assign(n,-1);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, -1); articulation_vertex.assign(n, 0);
        dfsRoot = 0;rootChildren = 0;
        articulationPointAndBridge(0);
        articulation_vertex[0] = (rootChildren > 1)?1:0;
        int counter = 0;
        for (int i = 0; i < n; i++)
            if (articulation_vertex[i] == 1)
                counter++;
        printf("%d\n",counter);
    }
    return 0;
}

