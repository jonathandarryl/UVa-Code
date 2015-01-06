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
#define EPS 1e-9
double memo[9][1<<9];
double dist[9][9];
int n;
typedef struct{
    int x,y;
}Point;

Point point[9];

bool sort_cmp(Point a, Point b){
    if(a.x!=b.x)a.x<b.x;
    else a.y<b.y;
}
double tsp(int pos, int bitmask){
    if(bitmask == (1<<n)-1){
        return 0;
    }
    if(memo[pos][bitmask]>-0.5) return memo[pos][bitmask];

    double ans = INFLL;
    FOR(i,n){
        if(i!=pos && !(bitmask & (1<<i))){
            //    printf("trying %d %d\n",pos,i);
            ans = min(ans,dist[pos][i]+tsp(i,bitmask | (1<<i)));
            //printf("result of %d %d: %lf\n",pos,i,ans);
        }
    }
    return memo[pos][bitmask] = ans;
}

void print_path(int pos, int bitmask){
    if(bitmask == (1<<n)-1) return;
    FOR(i,n){
        //printf("",i,tsp(i, bitmask|(1<<i)),memo[pos][bitmask]);
        if(i != pos && (abs(dist[pos][i] + tsp(i, bitmask|(1<<i)) - memo[pos][bitmask])< EPS)){
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",point[pos].x,point[pos].y,point[i].x,point[i].y,16+dist[pos][i]);
            print_path(i,bitmask | (1<<i));
            break;
        }
    }
}

int main(void){
    //freopen("in.txt","r",stdin);

    int casecounter = 1;
    while(scanf("%d",&n),n){

        FOR(i,n){
            scanf("%d %d",&point[i].x,&point[i].y);
        }

        sort(point,point+n,sort_cmp);

        FOR(i,n){
            dist[i][i] = 0;
            REP(j,i+1,n){
                dist[i][j] = dist[j][i] = hypot(abs(point[i].x-point[j].x), abs(point[i].y-point[j].y));
            }
        }

        //reset(memo,-1);
        double ans = INFLL;
        int idx;
        FOR(i,n){
            reset(memo,-1);
            tsp(i,1<<i);
            if(memo[i][1<<i] < ans){
                ans = memo[i][1<<i];
                idx = i;
            }
        }
        tsp(idx,1<<idx);
        printf("**********************************************************\n");
        printf("Network #%d\n",casecounter++);
        print_path(idx,1<<idx);
        printf("Number of feet of cable required is %.2lf.\n",(n-1)*16 + memo[idx][1<<idx]);
    }

    return 0;
}
