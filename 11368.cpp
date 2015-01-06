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

typedef struct{
    int x,y;
}dol;

bool sort_cmp(dol a, dol b){
    if(a.x != b.x)return a.x<b.x;
    return a.y<b.y;
}

int main(void){
    int tc;
    dol doll[20010];
    int L[20010], L_id[20010], P[20010];
    scanf("%d",&tc);
    TC(){
        int n;
        scanf("%d",&n);
        FOR(i,n){
            scanf("%d %d",&doll[i].x,&doll[i].y);
        }
        sort(doll,doll+n,sort_cmp);
          int lis = 0, lis_end = 0;
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(L, L + lis, doll[i].y) - L;
            L[pos] = doll[i].y;
            L_id[pos] = i;
            P[i] = pos ? L_id[pos - 1] : -1;
            if (pos + 1 > lis) {
                lis = pos + 1;
                lis_end = i;
            }
        }
        printf("%d\n",lis);
    }

    return 0;
}
