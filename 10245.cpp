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
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
typedef struct{
    int x,y;
}point;

bool sort_cmp(point a, point b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

int main(void){
    //freopen("in.txt","r",stdin);
    int n;
    point pt[10001];
    while(scanf("%d",&n),n){
        FOR(i,n){
            scanf("%d %d",&pt[i].x,&pt[i].y);
        }
        sort(pt,pt+n,sort_cmp);
        double shortest = INFLL;
        FOR(i,n){
            REP(j,i+1,n){
                double dist = hypot(abs(pt[i].x-pt[j].x),abs(pt[i].y-pt[j].y));
                if(dist<shortest){
                    shortest = dist;
                }else break;
            }
        }
        if(shortest>=10000)printf("INFINITY\n");
        else printf("%.4lf\n",shortest);
    }
    return 0;
}
