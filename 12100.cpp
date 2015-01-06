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
    #ifdef ccsnoopy
        freopen("D:/Code/in.txt","r",stdin);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int tc;
    int arr[102];
    sc(tc);
    TC(){
        int n,m;
        queue<int> q;
        sc(n);sc(m);
        FOR(i,n){
            sc(arr[i]);
            q.push(arr[i]);
        }
        sort(arr,arr+n);
        reverse(arr,arr+n);
        int highest = 0;
        int total = 0;
        while(true){
            int y = q.front();
            q.pop();
            if(y!=arr[highest]){
                q.push(y);
                if(m==0)m=n-1;
                else m--;
            }else{
                total++;
                if(m==0)break;
                n--;
                m--;
                highest++;
            }
        }
        printf("%d\n",total);
    }

    return 0;
}



