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
    string str;
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    int arr[10];
    int x,y,x1,y1;
    vector<vi>AdjList;
    AdjList.assign(9,vi());
    FOR(j,9){
        x = j/3;
        y = j%3;
        FOR(i,4){
            x1 = x+dr[i];
            y1 = y+dc[i];
            if(x1>=0 && y1>=0 && x1<3 && y1<3){
                    //printf("%d %d with %d %d\n",x,y,x1,y1);
                AdjList[x*3+y].pb(x1*3+y1);
            }
        }
    }
    int tc = 1;
    while(getline(cin,str)){
        reset(arr,0);
        int len = str.length();
        int num;
        FOR(i,len){
            num = str.at(i)-'a';
            arr[num]++;
            //printf("%d\n",num);

            FOR(j,AdjList[num].size()){
                arr[AdjList[num][j]]++;
                //printf("%d %d %d\n",num,AdjList[num][j],arr[AdjList[num][j]]);
            }
        }
        printf("Case #%d:\n",tc++);
        FOR(i,3){
            FOR(j,3){
                if(j<2)printf("%d ",arr[i*3+j]%10);
                else printf("%d",arr[i*3+j]%10);
            }printf("\n");
        }
    }

    return 0;
}



