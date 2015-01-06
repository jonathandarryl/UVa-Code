#include <bits/stdc++.h>
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
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

vi S, visited;
vector<vi> AdjList;
int dfsNumberCounter;
int numSCC; //strongly connected Component
vi dfs_low, dfs_num;
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        printf("SCC %d:", ++numSCC);
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            printf(" %d", v);
            if (u == v) break;
        }
        printf("\n");
} }


int main(void){
    #ifdef ccsnoopy
        freopen("D:/Code/in.txt","r",stdin);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int m,n;
    int fr,to,way;
    while(scanf("%d %d",&m,&n) && (m||n)){
        AdjList.assign(m,vi());
        FOR(i,n){
            sc(fr);sc(to);sc(way);
            fr--;to--;
            AdjList[fr].pb(to);
            if(way == 2)AdjList[to].pb(fr);
        }
        dfsNumberCounter = numSCC = 0;
        visited.assign(m,0);dfs_num.assign(m, -1); dfs_low.assign(m, 0);
        tarjanSCC(0);
        bool valid = true;
        FOR(i,m){
            if(visited[i] == 0){valid = false;printf("%d\n",i);}
        }
        if(valid && numSCC == 1){
            printf("1\n");
        }else printf("0\n");
    }

    return 0;
}



