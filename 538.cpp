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
typedef struct{
    int num, balance;
    string str;
}trav;

bool sort_cmp(trav a, trav b){
    return a.balance>b.balance;
}

int main(void){
    #ifdef ccsnoopy
        freopen("D:/Code/in.txt","r",stdin);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int n,t;
    string name,namez;
    map<string,int>mapper;
    trav traveller[24];
    int tc = 1;
    while(scanf("%d %d",&n,&t) && (n||t)){
        printf("Case #%d\n",tc++);
        FOR(i,n){
            cin>>name;
            mapper[name] = i;
            traveller[i].num = i;
            traveller[i].balance = 0;
            traveller[i].str = name;
        }
        int amt;
        FOR(i,t){
            cin>>name>>namez;
            sc(amt);
            traveller[mapper[name]].balance-=amt;
            traveller[mapper[namez]].balance+=amt;
        }
        sort(traveller,traveller+n,sort_cmp);
        int ptr = n-1;
        FOR(i,n){
            while(traveller[i].balance!=0){
                int sumbang = min(abs(traveller[i].balance),abs(traveller[ptr].balance));
                traveller[i].balance-=sumbang;
                traveller[ptr].balance+=sumbang;
                cout<<traveller[i].str<<" "<<traveller[ptr].str<<" "<<sumbang<<endl;
                if(traveller[ptr].balance==0)ptr--;

            }
        }
        printf("\n");
    }

    return 0;
}



