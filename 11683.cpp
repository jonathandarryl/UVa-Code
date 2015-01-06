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
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

int main(void){
    //freopen("D:/Code/in.txt","r",stdin);
    int a,c;
    int arr[10030];
    while(scanf("%d %d",&a,&c) && a){
       stack <int> s;
        int num, cnt = 0;
        scanf ("%d", &num);
        s.push(num);

        for ( int i = 1; i < c; i++ ) {
            scanf ("%d", &num);
            if ( num == s.top() ) continue;
            else if ( num < s.top() ) {
                s.pop();
                s.push(num);
            }
            else {
                cnt += (num - s.top());
                s.pop();
                s.push(num);
            }
        }

        cnt += (a - s.top());
        printf ("%d\n", cnt);

    }

    return 0;
}


