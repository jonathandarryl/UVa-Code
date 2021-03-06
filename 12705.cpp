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
    sc(tc);
    string str;
    int arr[40];
    FOR(i,6){
        FOR(j,6) arr[i*6+j] = i+j+2;
    }
    sort(arr,arr+36);
    getline(cin,str);
    int val[40];
    TC(){
        getline(cin,str);
        reset(val,0);
        int len = str.length();
        FOR(i,len){
            char x = str.at(i);
            if(x!=' '){
                if(x>='A' && x<='Z')val[x-'A']++;
                else val[x-'0'+26]++;
            }
        }
        sort(val,val+36);
        reverse(val,val+36);
        int total = 0;
        FOR(i,36){
            total+=arr[i]*val[i];
        }
        printf("%d\n",total);
    }

    return 0;
}



