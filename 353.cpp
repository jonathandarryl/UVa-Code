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
#define FORN(i,n) for(int i=0;i<=n;;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))

int main(void){

    freopen("in.txt","r",stdin);
    map<string,int> mapper;
    string str,str2;
    while(cin>>str){
        mapper.clear();
        int len = str.length();
        FOR(i,len){
            REPN(j,1,len-i){
                str2 = str.substr(i,j);
                int leng = str2.length();
                if(mapper.find(str2)==mapper.end()){
                    bool found = true;
                    FOR(k,leng){
                        if(str2.at(k)!=str2.at(leng-1-k)){
                            found = false;
                            break;
                        }
                    }
                    if(found)mapper[str2]++;
                }
            }
        }
        printf("The %d unique palindromes in '%s' are ",mapper.size(),str.c_str());
        mapper<string,int>::iterator it = mapper.begin();
        int counter =
        for(;it!=mapper.end();it++){
            printf("'%s'",it->first.c_str());
        }
    }


    return 0;
}
