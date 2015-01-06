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
#define MAX_N 3

typedef struct{
    ll mat[3][3];
}Matrix;

Matrix matMul(Matrix a, Matrix b){
	Matrix ans; int i,j,k;
	for(i=0;i<MAX_N;i++)
        for(j=0;j<MAX_N;j++)
            for(ans.mat[i][j] = k = 0;k<MAX_N; k++)
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k]%1000000009 * b.mat[k][j]%1000000009)%1000000009;
    return ans;
}

Matrix matPow(Matrix base, ll p){
	Matrix ans; int i,j;
	for(i=0;i<MAX_N;i++) for(j=0;j<MAX_N;j++) ans.mat[i][j] = (i==j);
    while(p){
        if(p&1) ans = matMul(ans,base);
        base = matMul(base,base);
        p>>=1;
    }
    return ans;
    }

int main(void){
    //freopen("in.txt","r",stdin);
    Matrix trib;
//    trib.mat = {{1,1,0},{1,0,1},{1,0,0}};
    trib.mat[0][0] = trib.mat[0][1] = trib.mat[0][2] = trib.mat[1][0] = trib.mat[2][1] = 1;
    trib.mat[1][1] = trib.mat[1][2] = trib.mat[2][0] = trib.mat[2][2] = 0;
    ll n;
    while(scanf("%lld",&n),n){
        printf("%lld\n",matPow(trib,n).mat[1][1]);
    }
    return 0;
}
