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

unsigned long long memo[65][65];
unsigned long long trib(int n, int back)
{
    //printf("%d %d\n",n,back);
    if(n >= 0 && memo[n][back]!=-1)return memo[n][back];
    int i;
    unsigned long long ct = 1;
    //ct++;
    if(n<0) return 1;
    if(n==1 || n==0) return memo[n][back] = 1;
    for(i=1;i<=back;i++)
         ct+=trib(n-i,back);
    //memo[n][back] = ct;
    return memo[n][back] = ct;
}

int main(void){
    memset(memo,-1,sizeof memo);
    //freopen("out.txt","w",stdout);
    //trib(60,60);
    int casecounter = 1;
    int n, back;
    while(scanf("%d %d",&n,&back) && n<=60){
        printf("Case %d: %llu\n",casecounter++,trib(n,back));
    }
    return 0;
}
