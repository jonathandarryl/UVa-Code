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
#define isOn(S, j) (S & (1 << j)) //check if the bit is on
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j)) //set bit to 0

int main(void){
    freopen("in.txt","r",stdin);
    int casecounter = 1;
    int n;
    int x[81],y[81],z[81],val[81];
    while(scanf("%d",&n),n){
        FOR(i,n){
            scanf("%d %d %d %d",&x[i],&y[i],&z[i],&val[i]);
        }
        int maxi = -1;
        int bitmask = 0;
        int total;
        FOR(i,n-2){
            total = val[i];
            setBit(bitmask,x[i]);
            setBit(bitmask,y[i]);
            setBit(bitmask,z[i]);
            FOR(j,n-1){
                if((!isOn(bitmask,x[j])) && (!isOn(bitmask,y[j]) && (!isOn(bitmask,z[j])))){
                    setBit(bitmask,x[j]);
                    setBit(bitmask,y[j]);
                    setBit(bitmask,z[j]);
                    total+=val[j];
                    FOR(k,n){
                        if((!isOn(bitmask,x[k])) && (!isOn(bitmask,y[k]) && (!isOn(bitmask,z[k])))){
                            maxi = max(total+val[k],maxi);
                        }
                    }
                    total-=val[j];
                    clearBit(bitmask,x[j]);clearBit(bitmask,y[j]);clearBit(bitmask,z[j]);
                }
            }
            clearBit(bitmask,x[i]);clearBit(bitmask,y[i]);clearBit(bitmask,z[i]);

        }
        printf("Case %d: %d\n",casecounter++,maxi);

    }
    return 0;
}
