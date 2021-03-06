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
    int r, a, b;
    while(scanf("%d %d %d",&r,&a,&b)!=EOF){
        if(a>b){
            int temp =  a;
            a = b;
            b = temp;
        }
        FOR(i,r){
            if(a%2 == 1 && b%2 == 0 && (b-a) == 1){
                printf("%d\n",i+1);
                break;
            }
            if(a%2 == 0) a>>=1;
            else {a++;a>>=1;}
            if(b%2 == 0) b>>=1;
            else {b++;b>>=1;}

            if(a>b){
                int temp  =a;
                a = b;
                b = temp;
            }

        }
    }
    return 0;
}


