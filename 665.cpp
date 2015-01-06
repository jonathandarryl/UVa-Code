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
    bool arr[103];
    int left[60],right[60];
    sc(tc);
    bool first = true;
    char str[4];
    TC(){
        if(!first){
            printf("\n");
        }else first = false;
        int n,k;
        sc(n);
        sc(k);
        FORN(i,n)arr[i] = false;
        int test;
        FOR(i,k){
            sc(test);
            FOR(j,test){
                sc(left[j]);
            }
            FOR(j,test){
                sc(right[j]);
            }
            scanf("%s",str);
            //printf("%s",str);
            if(str[0]=='='){
                FOR(j,test){
                    //printf("%d %d\n",left[j],right[j]);
                    arr[left[j]] = true;
                    arr[right[j]] = true;
                }
            }else{
                bool status[103];
                reset(status,false);
                FOR(j,test){
                    status[left[j]] = status[right[j]] = true;
                }
                REPN(j,1,n){
                    if(!status[j])arr[j] = true;
                }
            }
        }
        int tot = 0;
        int idx;
        /*REPN(i,1,n){
            if(!arr[i])printf("%d\n",i);
        }*/
        REPN(i,1,n){
            if(!arr[i]){
                tot++;
                idx = i;
            }
            if(tot>1)break;
        }
        if(tot == 1){
            printf("%d\n",idx);
        }else printf("0\n");

    }
    return 0;
}


