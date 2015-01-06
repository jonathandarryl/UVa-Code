//WA
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
    double l,w,d;
    double we;
    int tc;
    int total = 0;
    sc(tc);
    TC(){
        scanf("%lf %lf %lf %lf",&l,&w,&d,&we);
        bool valid = true;
        //printf("%lf %lf %lf %lf\n",l,w,d,we);
        if((l > 56.000 && w > 45.000 && d > 25.000) || l+w+d > 125.000) valid = false;
        if(we > 7.000) valid = false;
        if(valid){printf("1\n");total++;}
        else printf("0\n");
    }
    printf("%d\n",total);
    return 0;
}

