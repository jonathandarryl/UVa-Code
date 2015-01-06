
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

int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    ll box[27][27];
    string str;
    getline(cin,str);
    getline(cin,str);
    TC(){
        reset(box,0);
        int counter = 0;
        int len = 0;
        while(getline(cin,str)){
            if(str==""){
                //printf("ga ada apa2");
                break;
            }
            len = str.length();
            FOR(i,len){
                if(str.at(i)=='1')box[counter][i] = 1;
                else box[counter][i] = -INF;
                if(i>0) box[counter][i]+=box[counter][i-1];
                if(counter>0) box[counter][i]+=box[counter-1][i];
                if(i>0 && counter>0)box[counter][i] -= box[counter-1][i-1];

            }
            counter++;
        }
        /*FOR(i,counter){
            FOR(j,len) printf("%lld ",box[i][j]);
            printf("\n");
        }*/
        ll optimum = 0, subRect;
        FOR(i,counter){
            FOR(j,len){
                REP(k,i,counter){
                    REP(l,j,len){
                        subRect = box[k][l];
                        if(i>0) subRect -= box[i-1][l];
                        if(j>0) subRect -= box[k][j-1];
                        if(i>0 && j>0) subRect += box[i-1][j-1];
                        optimum = max(optimum, subRect);
                    }
                }
            }
        }
        printf("%lld\n",optimum);
        if(tc)printf("\n");
    }
    return 0;
}
