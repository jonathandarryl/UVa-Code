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

int lowLimit;
int highLimit;
int dp [100] [100];
int n, t, p;

int bktk (int sum, int index)
{
    if ( sum > t ) 
	{
		printf ("go here");
    	return 0;
	}

    if ( index == n ) {
        if ( sum == t ) return 1;
        return 0;
    }

    if ( dp [sum] [index] != -1 )
        return dp [sum] [index];

    dp [sum] [index] = 0;
    int ret = 0;


    for ( int i = lowLimit; i <= highLimit; i++ ) {
        sum += i;
        ret += bktk (sum, index + 1);
        sum -= i;
    }

    return dp [sum] [index] = ret;

}


int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        scanf ("%d %d %d", &n, &t, &p);

        lowLimit = p;
        highLimit = t - p * (n - 1);

        reset (dp,-1);

        //bktk (0, 0);

        printf ("%d\n", bktk (0, 0));

    }

    return 0;
}
