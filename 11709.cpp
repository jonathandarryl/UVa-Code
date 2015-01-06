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
#define DFS_WHITE -1
vector<vi> AdjList;
vi dfs_num, dfs_low;
int V,m;
string str;
vi S, visited;                                    // additional global variables
int numSCC;
int dfsNumberCounter;
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;      // dfs_low[u] <= dfs_num[u]
    S.push_back(u);           // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == DFS_WHITE)
            tarjanSCC(v);
        if (visited[v])                                // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {         // if this is a root (start) of an SCC
        numSCC++;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            //printf(" %d", v);
            if (u == v) break;
        }
        //printf("\n");
} }
int main(void){
    //freopen("in.txt","r",stdin);
    map<string,int> mapper;
    while(scanf("%d %d",&V,&m),(V||m)){
            mapper.clear();
        getline(cin,str);
        FOR(i,V){
            getline(cin,str);
            mapper[str] = i;
        }
        string fr, to;
        AdjList.assign(V,vi());
        FOR(i,m){
            getline(cin,fr);
            getline(cin,to);
            AdjList[mapper[fr]].pb(mapper[to]);
            //AdjList[mapper[to]].pb(mapper[fr]);
        }
        dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == DFS_WHITE)
                tarjanSCC(i);
        printf("%d\n",numSCC);
    }
    return 0;
}
