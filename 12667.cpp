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
    int n, m, t;
    scanf("%d %d %d",&n,&t,&m);
    int submission[105][14];
    reset(submission,-1);
    char prob[3];
    char verdict[5];
    ii soln[20];
    int time, id;
    int probnumber;
    FOR(i,n) soln[i] = ii(-1,-1);
    FOR(i,m){
        scanf("%d %d %s %s",&time,&id,prob,verdict);
        probnumber = prob[0]-'A';
        if(verdict[0] == 'N' || submission[id][probnumber] != -1)continue;
        //probnumber = prob[0]-'A';
        submission[id][probnumber] = time;
        soln[probnumber] = ii(time,id);
    }
    FOR(i,n){
        printf("%c ",'A'+i);
        if(soln[i].first == -1)printf("- -\n");
        else printf("%d %d\n",soln[i].first,soln[i].second);
    }
    return 0;
}

