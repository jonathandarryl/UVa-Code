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

double memo2d[500][500];
double d[500][500];
int n;


double dp(int p1, int p2){ //called with dp(0,0)
    int v = 1 + max(p1, p2);
    if(v == n-1){
        return d[p1][v] + d[v][p2];
    }
    if(memo2d[p1][p2] > -0.5){
        return memo2d[p1][p2];
    }return memo2d[p1][p2] = min(
        d[p1][v] + dp(v,p2),d[v][p2]+dp(p1,v));
}


int main(void){
    //freopen("in.txt","r",stdin);
    vi xi, yi;
    int x,y;
    while(scanf("%d",&n)!=EOF){
        memset(memo2d,-1,sizeof memo2d);
        xi.clear();yi.clear();
        FOR(i,n){
            scanf("%d %d",&x,&y);
            xi.pb(x);
            yi.pb(y);
        }
        FOR(i,n){
            d[i][i] = 0;
            REP(j,i+1,n){
                d[i][j] = d[j][i] = hypot(abs(xi[i]-xi[j]),abs(yi[i]-yi[j]));
            }
        }
        printf("%.2lf\n",dp(0,0));
    }
    return 0;
}
