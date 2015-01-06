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
    #ifdef ccsnoopy
        freopen("D:/Code/in.txt","r",stdin);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    double a,b,c;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3){
        if((a+b)>c && (b+c)>a && (a+c)>b){
            double s = a+b+c;
            s/=2;
            printf("%.3lf\n",4*sqrt(s*(s-a)*(s-b)*(s-c))/3);
        }else printf("-1.000\n");
    }

    return 0;
}



