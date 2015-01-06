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
int price[10], n;
int combo;
int deal[12][12];
int memo[1000000];

int demand(int demand[]){
    int num = 0;
    FOR(i,n){
        num = num*10 + demand[i];
    }
    if(memo[num]!=-1)return memo[num];
    int ans = INF;
    FOR(i,combo){

    }
    FOR(i,n){

    }
    return memo[num] = ans;

}

int main(void){
//    #ifndef DEBUG
    freopen("in.txt","r",stdin);
  //  #endif
    int demand[10];
    while(scanf("%d",&n)!=EOF){
        FOR(i,n){
            scanf("%d",&price[i]);
        }
        //demand.assign(n,0);
        scanf("%d",&combo);
        FOR(i,combo){
            FOR(j,n){
                scanf("%d",&deal[i][j]);
            }
            scanf("%d",&deal[i][n]);
        }
        int tc;
        memset(memo,-1,sizeof memo);
        scanf("%d",&tc);
        TC(){
            FOR(i,n){
                scanf("%d",&demand[i]);
            }
            printf("%d\n",dp(demand));
        }
    }
    return 0;
}
