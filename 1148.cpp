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

int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    vector<vi> AdjList;
    TC(){
        int n;
        scanf("%d",&n);
        AdjList.assign(n,vi());
        int cam,tmn,fr,to;
        FOR(i,n){
            scanf("%d",&cam);
            scanf("%d",&tmn);
            FOR(j,tmn){
                scanf("%d",&fr);
                AdjList[fr].pb(cam);
                AdjList[cam].pb(fr);
            }
        }
        scanf("%d %d",&fr,&to);
        vi dist;
        dist.assign(n,INF);
        queue<int> q;
        q.push(fr);
        dist[fr] = 0;
        while(!q.empty()){
            int v = q.front();q.pop();
            FOR(i,AdjList[v].size()){
                int u = AdjList[v][i];
                if(dist[u] > dist[v] + 1){
                    q.push(u);
                    dist[u] = dist[v]+1;
                }
            }
            if(dist[to]!=INF)break;
        }
        printf("%d %d %d\n",fr,to,dist[to]-1);
        if(tc)printf("\n");
    }
    return 0;
}
