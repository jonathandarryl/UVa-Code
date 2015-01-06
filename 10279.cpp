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
    int tc;
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};
    int bombs[13][13];
    char str2[13][13];
    sc(tc);
    int n;
    char str[13][13];
    bool first = true;
    TC(){
        reset(bombs,0);
        if(first)first = false;
        else printf("\n");
        sc(n);
        FOR(i,n){
            scanf("%s",str[i]);
            FOR(j,n){
                if(str[i][j] == '*'){
                    FOR(k,8){
                        int x2,y2;
                        x2 = i+dr[k];
                        y2 = j+dc[k];
                        if(x2>=0 && x2<n && y2>=0 && y2<n)
                            bombs[x2][y2]++;
                    }
                }
            }
        }
        bool bombed = false;
        FOR(i,n){
            scanf("%s",str2[i]);
            FOR(j,n){
                if(str[i][j] == '*' && str2[i][j] == 'x')bombed = true;
            }
        }
        if(bombed){
            FOR(i,n){
                FOR(j,n){
                    if(str[i][j] == '*')printf("*");
                    else if(str2[i][j] == 'x' && str[i][j]!='*')printf("%d",bombs[i][j]);
                    else printf(".");
                }
                printf("\n");
            }

        }else{
            FOR(i,n){
                FOR(j,n){
                    if(str2[i][j]=='x')printf("%d",bombs[i][j]);
                    else printf(".");
                }
                printf("\n");
            }
        }
    }
    return 0;
}


