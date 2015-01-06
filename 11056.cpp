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
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
typedef struct{
    string name,compname;
    int mins, sec, ms;
}racer;

bool sort_cmp(racer a, racer b){
    if(a.mins != b.mins)return a.mins<b.mins;
    if(a.sec != b.sec) return a.sec<b.sec;
    if(a.ms != b.ms) return a.ms<b.ms;
    return a.compname.compare(b.compname) < 0;
}

int main(void){
    //freopen("in.txt","r",stdin);
    int n;
    racer race[102];
    while(scanf("%d",&n)!=EOF){
        string dummy;
        FOR(i,n){

            cin>>race[i].name>>dummy>>race[i].mins>>dummy>>race[i].sec>>dummy>>race[i].ms>>dummy;
            string x = "";
            FOR(j,race[i].name.length()){
                 x += tolower(race[i].name.at(j));
            }
            race[i].compname = x;
            //scanf("%s : %d min %d sec %d ms",race[i].name,race[i].mins,race[i].sec,race[i].ms);
        }
        sort(race,race+n,sort_cmp);
        int counter = 0;
        FOR(i,n){
            if(i%2 == 0){
                counter++;
                printf("Row %d\n",counter);
            }
            cout<<race[i].name<<endl;
            //printf("%s\n",race[i].name);
        }
        printf("\n");
    }
    return 0;
}

