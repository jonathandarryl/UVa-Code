
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

    ll box[102][102];
    int n,m;
    while(scanf("%d %d",&n,&m),(n||m)){
        reset(box,0);
        int counter = 0;
            FOR(i,n){
                FOR(j,m){
                    scanf("%lld",&box[i][j]);
                    if(box[i][j] == 1) box[i][j] = -INF;
                    else box[i][j] = 1;
                    if(i>0) box[i][j] += box[i-1][j];
                    if(j>0) box[i][j] += box[i][j-1];
                    if(i>0 && j>0) box[i][j] -= box[i-1][j-1];
                }
            }

        /*FOR(i,counter){
            FOR(j,len) printf("%lld ",box[i][j]);
            printf("\n");
        }*/
        ll optimum = 0, subRect;
        FOR(i,n){
            FOR(j,m){
                REP(k,i,n){
                    REP(l,j,m){
                        subRect = box[k][l];
                        if(i>0) subRect -= box[i-1][l];
                        if(j>0) subRect -= box[k][j-1];
                        if(i>0 && j>0) subRect += box[i-1][j-1];
                        optimum = max(optimum, subRect);
                    }
                }
            }
        }
        printf("%lld\n",optimum);

    }
    return 0;
}
