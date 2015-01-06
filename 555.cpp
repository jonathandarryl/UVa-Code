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

map<char,int> mapper;
typedef struct{
    char name[2];
}card;

typedef vector<card> vcard;

int main(void){
    freopen("D:/Code/in.txt","r",stdin);
    char arah[5];
    char kartu[50];
    mapper['N'] = 0;
    mapper['E'] = 1;
    mapper['S'] = 2;
    mapper['W'] = 3;
    //vector<card> vcard;
    vector<vcard>vvc;
    int now;
    while(scanf("%s",arah) && arah[0]!='#'){
        now = mapper[arah[0]];
        vvc.assign(4,vcard());
        FOR(i,2){
            scanf("%s",kartu);
            FOR(j,13){
                card x;
                x.name[0] = kartu[2*j];
                x.name[1] = kartu[2*j+1];
                vvc[now].pb(x);
                now++;
                now = now % 4;
            }
        }
        FOR(i,4){
            FOR(j,13){
                printf("%c%c ",vvc[i][j].name[0],vvc[i][j].name[1]);
            }printf("\n");
        }
    }
    return 0;
}


