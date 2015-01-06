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
    int in[101];
    vector<vi> AdjList;
    while(scanf("%d %d",&n,&m),(n||m)){
        AdjList.assign(n,vi());
        reset(in,0);
        int fr,to;
        FOR(i,m){
            scanf("%d %d",&fr,&to);
            fr--,to--;
            in[to]++;
            AdjList[fr].pb(to);
        }
        queue<int> q;
        FOR(i,n){
            if(!in[i])q.push(i);
        }
        vi toposort;
        while(!q.empty()){
            int v = q.front();q.pop();
            toposort.pb(v);
            int sizes = AdjList[v].size();
            FOR(i,sizes){
                int node = AdjList[v][i];
                in[node]--;
                if(!in[node])q.push(node);
            }
        }
        printf("%d",toposort[0]+1);
        REP(i,1,toposort.size()){
            printf(" %d",toposort[i]+1);
        }
        printf("\n");
    }
    return 0;
}
