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

int val[15][105], weight[15][105], parent[15][105];

void compare(int x1, int y1, int x2, int y2){
    if(weight[x1][y1]>weight[x2][y2] + val[x1][y1]){
        parent[x1][y1] = x2;
        weight[x1][y1] = weight[x2][y2] + val[x1][y1];
    }
}

int main(void){
    freopen("in.txt","r",stdin);
    int n,m;
    vector<vi> path;
    while(scanf("%d %d",&m,&n)!=EOF){
        FOR(i,m){
            FOR(j,n){
                scanf("%d",&val[i][j]);
                weight[i][j] = INF;
            }
        }
        FOR(i,m){
            weight[i][0] = val[i][0];
            parent[i][0] = i;
        }
        REP(j,1,n){
            FOR(i,m){
                //compare(i,j,(i-1+m)%m,j-1);
                //compare(i,j,i,j-1);
                //compare(i,j,(i+1)%m,j-1);
                if(i == 0){
                    compare(i,j,0,j-1);
                    //printf("comparing: %d\n",((i-1)%m+m)%m);
                    compare(i,j,(i+1)%m,j-1);
                    compare(i,j,(i+m-1)%m,j-1);
                }else if(i == m-1){
                    compare(i,j,(i+1)%m,j-1);
                    compare(i,j,(i+m-1)%m,j-1);
                    compare(i,j,i,j-1);
                }else{
                    compare(i,j,i-1,j-1);
                    compare(i,j,i,j-1);
                    compare(i,j,i+1,j-1);
                }

            }
        }
        int minweight = INF;

        path.clear();
        int idx = -1;
        FOR(i,m){
            //printf("%d  %d\n",weight[i][n-1]);
            if(minweight > weight[i][n-1]){
                minweight = weight[i][n-1];
                //printf("minweight now: %d\n",minweight);
                idx = i;
            }
        }
        int counter = 0;
        FOR(i,m){
            if(minweight == weight[i][n-1]){
                path.pb(vector<int>());
                for(int j=n-1;j>=0;j--){
                path[counter].pb(idx+1);
                idx = parent[idx][j];
                }
                counter++;
            }
        }
        FOR(i,counter)reverse(path[i].begin(),path[i].end());
        int best;
        //FOR(i,path.size()){

        //}
        FOR(i,path.size()){
        FOR(j,path[0].size()){
            printf("%d ",path[i][j]);
        }printf("\n");}
        printf("%d\n%d\n",path[0][path[0].size()-1],minweight);


    }
    return 0;
}
