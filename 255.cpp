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
    freopen("D:/Code/in.txt","r",stdin);
    int k,q,q2;
    while(scanf("%d %d %d",&k,&q,&q2)!=EOF){
        if(k == q)printf("Illegal state\n");
        else{
            bool ilmove = false;
            bool stuck = false;
            bool notallowed = false;
            if(k == q2)ilmove = true;
            int oldx, oldy, newx, newy, kingx, kingy;
            kingx = k/8;
            kingy = k%8;
            oldx = q/8;
            oldy = q%8;
            newx = q2/8;
            newy = q2%8;
            if(oldx != newx && oldy != newy)ilmove = true;
            if(q == q2)ilmove = true;
            if(!ilmove){
                if(oldx == newx){
                    int a = min(oldy,newy);
                    int b = max(oldy,newy);
                    REPN(i,a,b){
                        if(oldx == kingx && i==kingy)ilmove = true;
                    }
                }
                else{
                    int a= min(oldx,newx);
                    int b = max(oldx,newx);
                    REPN(i,a,b){
                        if(oldy == kingy && i == kingx)ilmove = true;
                    }
                }
            }

        }


    }
    return 0;
}


