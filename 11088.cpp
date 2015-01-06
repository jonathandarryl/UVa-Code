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
int member[35];
int memo[1<<16];


int N, val[100], best[65536];

int main() {
	for (int cs = 1; scanf("%d", &N) == 1 && N > 0; cs++) {
		FOR(i,N) scanf("%d", &val[i]);

		best[0] = 0;
		for (int u = 1; u < (1 << N); u++) {
			int i;
			for (i = 0; i < N && (u&(1<<i))==0; i++);
			best[u] = best[u^(1<<i)];

			for (int j = i+1; j < N; j++) if (u & (1 << j))
				for (int k = j+1; k < N; k++) if (u & (1 << k))
					if (val[i]+val[j]+val[k] >= 20)
						best[u]  = max(best[u], 1 + best[u^(1<<i)^(1<<j)^(1<<k)]);
		}

		printf("Case %d: %d\n", cs, best[(1<<N)-1]);
	}
}
