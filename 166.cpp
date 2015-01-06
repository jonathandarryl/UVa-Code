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

int change[10000], changeopt[502];
int num[] = {5,10,20,50,100,200};
int opt(int money, int coin[]){
    if(money == 0) return change[0] = 0;
    if(money < 0) return INF;
    if(change[money]!=-1) return change[money];
    int optans = INF;
    FOR(i,6){
        if(coin[i]>0){
            coin[i]--;
            optans = min(optans,1+opt(money-num[i],coin));
            coin[i]++;
        }
    }
    return (change[money] = optans);
}

int opt2(int money){
    if(money == 0) return changeopt[0] = 0;
    if(money < 0) return INF;
    if(changeopt[money]!=0) return changeopt[money];
    int optans = INF;
    FOR(i,6)
        optans = min(optans, 1+opt2(money-num[i]));
    return changeopt[money] = optans;
}

int main(void){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int coin[6];
    double money;
    int monint;
    reset(changeopt,0);
    opt2(500);
    while(scanf("%d %d %d %d %d %d",&coin[0],&coin[1],&coin[2],&coin[3],&coin[4],&coin[5]),(coin[0]||coin[1]||coin[2]||coin[3]||coin[4]||coin[5])){
        int total = 0;
        FOR(i,6){
            total+=coin[i]*num[i];
        }
        scanf("%lf",&money);
        monint = money*100+1e-6;
        //printf("%d",monint);
        reset(change,-1);
        opt(total,coin);
        int optimal = INF;
        total = min(total,1000);
        for(int i=monint;i<=total,(i-monint)<=500;i+=5){
            if(change[i]!=-1)
                optimal = min(optimal,change[i]+changeopt[i-monint]);
            //if(optimal == 1)printf("%d %d %d\n",i,change[i],changeopt[i-monint]);
            //printf("%d: %d\n",i,optimal);
        }
        printf("%3d\n",optimal);
        //FOR(i,96)printf("%d: %d\n",i,change[i]);
    }
    return 0;
}
