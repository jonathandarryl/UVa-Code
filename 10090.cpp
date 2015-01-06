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
int gcd(int a, int b) {
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

int extended_euclid(int a, int b, int &x, int &y) {
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}
int mod(int a, int b) {
  return ((a%b)+b)%b;
}
// computes b such that ab = 1 (mod n), returns -1 on failure
int mod_inverse(int a, int n) {
  int x, y;
  int d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}

// computes x and y such that ax + by = c; on failure, x = y =-1
void linear_diophantine(int a, int b, int c, int &z, int &zz) {
  int d = gcd(a,b);
  if (c%d) {
    z = zz = -1;
  } else {
    z = c/d * mod_inverse(a/d, b/d);
    zz = (c-a*z)/b;
  }
}


int main(void){
    //freopen("in.txt","r",stdin);
    int a,b,n,x,y,z,zz;
    /*while(scanf("%d",&n),n){
        int dummy;
        scanf("%d %d",&dummy,&a);
        scanf("%d %d",&dummy,&b);
        linear_diophantine(a,b,n,x,y);
        if(z == zz && z == -1)printf("failed\n");
        else printf("%d %d %d %d %d\n",a,b,x,y,z,zz);
    }*/
    scanf("%d",&n);
    linear_diophantine(9,1,n,z,zz);
    printf("%d %d %d %d %d %d %d\n",a,b,n,x,y,z,zz);
    return 0;
}
