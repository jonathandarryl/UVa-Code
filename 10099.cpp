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
    int n,r;
    int counter = 1;
    int AdjMat[103][103];
    while(scanf("%d %d",&n,&r),(n||r)){
        printf("Scenario #%d\n",counter++);
        /*FORN(i,n){
            FORN(j,n) AdjMat[i][j] = INF;
            AdjMat[i][i] = 0;
        }*/
        reset(AdjMat,0);

        int fr, to, dist;
        FOR(i,r){
            sc(fr);sc(to);sc(dist);
            fr;to; dist--;
            AdjMat[fr][to] = AdjMat[to][fr] = dist;
        }
        REPN(k,1,n){
            REPN(i,1,n){
                REPN(j,1,n)
                    AdjMat[i][j] = AdjMat[j][i] = max(AdjMat[i][j], min(AdjMat[i][k],AdjMat[k][j]));
            }
        }

        /*REPN(i,1,n){
            REPN(j,1,n)printf("%d ",AdjMat[i][j]);
            printf("\n");
        }*/
        sc(fr);sc(to);sc(dist);
        //fr;to;

        //cout<<AdjMat[fr][to]<<dist<<endl;
        int total;
        if(fr == to) total = 0;
        else{
            total = (dist)/AdjMat[fr][to];

            if(dist % AdjMat[fr][to]!= 0) total++;
        }
        printf("Minimum Number of Trips = %d\n\n",total);
    }

    return 0;
}

