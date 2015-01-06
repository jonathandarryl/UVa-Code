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
#define LSOne(k) (k & (~k))
ll tree[501][501];
int max_x, max_y;

void update(int x, int y, ll value){
    int y1 = y;
    //printf("%d\n",LSOne(x));
    //scanf("%d",&x);
    while(x<=max_x){
        y = y1;
        while(y<=max_y){
            tree[x][y]+=value;
            y+=LSOne(y);
            //printf("x: %d y: %d\n",x,y);
        }x+=LSOne(x);
    }
}

ll query(int x, int y){
    ll sum = 0;int y1 = y;
    while(x>0){
        y = y1;
        while(y>0){
            sum+=tree[x][y];
            y-=LSOne(y);

        }x-=LSOne(x);
    }return sum;
}

ll query(int x1, int x2, int y1, int y2){
    return query(x2,y2) - ((x1==0)?0:query(x1-1,y2)) -
    ((y1==0)?0:query(x2,y1-1)) + ((x1==0||y1==0)?0:query(x1-1,y1-1));
}

int main(void){
    //freopen("in.txt","r",stdin);
    scanf("%d %d",&max_x,&max_y);
    //printf("%d %d\n",max_x,max_y);
    reset(tree,0);
    ll num;
    int x1,y1,x2,y2;
    ll val;
    REPN(i,1,max_x){
        REPN(j,1,max_y){
            scanf("%lld",&num);
            update(i,j,num);
        }
    }
    int query;
    char input;
    FOR(i,query){
        scanf("%c",&input);
        printf("%c",input);
        if(input == 'q'){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        }else{
            scanf("%d %d %lld",&x1,&y1,&val);
        }
    }
    return 0;
}
