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
    int n,m;
    vi out;
    vector<vi> AdjList;
    while(scanf("%d %d",&n,&m),(n||m)){
        out.assign(n+1,0);
        int a,b;
        AdjList.assign(n+1,vi());
        FOR(i,m){
            scanf("%d %d",&a,&b);
            AdjList[a].pb(b);
            out[b]++;
        }
        queue<int> q;
        REPN(i,1,n){
            if(out[i] == 0){
                q.push(i);
            }
        }
        vi toposort;
        bool valid = true;
        while(!q.empty()){
            int v = q.front();q.pop();
            toposort.pb(v);
            FOR(i,AdjList[v].size()){
                int x = AdjList[v][i];
                out[x]--;
                if(!out[x]){
                    q.push(x);
                }
            }
        }
        if(valid){
        FOR(i,toposort.size()){
            printf("%d\n",toposort[i]);
        }}
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
