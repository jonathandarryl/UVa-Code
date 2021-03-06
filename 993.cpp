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

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;

void sieve(ll upperbound) {    for(int i=9;i>=2;i--)primes.push_back((int)i);
 }

vi primeFactors(ll N) {   // remember: vi is vector of integers, ll is long long
  vi factors;                    // vi `primes' (generated by sieve) is optional
  ll PF_idx = 0, PF = primes[PF_idx];     // using PF = 2, 3, 4, ..., is also ok
  for(int i=9;i>=2;i--){
    while(N%i == 0){N/=i;factors.push_back(i);}
  }
  if (N != 1) factors.push_back(N);     // special case if N is actually a prime
  return factors;         // if pf exceeds 32-bit integer, you have to change vi
}

int main(void){
       // freopen("in.txt","r",stdin);
    int tc,n;
    vi vint;
    sieve(25);
    scanf("%d",&tc);
    TC(){
        scanf("%d",&n);
        if(n == 0 || n == 1)printf("%d\n",n);
        else{
            vint.clear();
            vint = primeFactors(n);
            sort(vint.begin(),vint.end());
            if(vint[vint.size()-1]>9){
                printf("-1\n");
            }
            else{
                FOR(i,vint.size()){
                    printf("%d",vint[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
