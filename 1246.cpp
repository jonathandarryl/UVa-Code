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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))

ll _sieve_size;
bitset<100010> bs;   // 10^7 should be enough for most cases
vi primes;

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();        // set all bits to 1
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
} }

ll numDiv(ll N) { //50 ==> 1, 2, 5, 10, 25, 50, 6 divisors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;                                             // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                              // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
  return ans;
}
bool isPrime(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;                    // it takes longer time if N is a large prime!
}
int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    bool arr[11010];
    int arr2[11010];
    reset(arr,false);
    reset(arr2,0);
    sieve(10000);
    scanf("%d",&tc);
    for(int i=2;i<=10000;i++){
        if(isPrime(numDiv(ll(i)))){
            arr[i] = true;
            arr2[i] = 1;
        }
        arr2[i] += arr2[i-1];
    }
    //while(true){}
    vector<int> v;
    TC(){

        v.clear();
        int L,H;
        scanf("%d %d",&L,&H);
        if(L > H){
            int temp = H;
            H = L;
            L = temp;
        }
        if(L == 0){
            if(arr2[H] == 0) printf("-1\n");
            else{
                //vector<int> v;
                for(int i=L;i<=H;i++){
                    if(arr[i]){
                        v.push_back(i);
                    }
                }
                for(int i=0;i<v.size()-1;i++){
                    printf("%d ",v[i]);
                }printf("%d\n",v[v.size()-1]);
            }
        }else{
            //printf("%d %d\n",H,L);
            if((arr2[H] - arr2[L-1])>0){
                //vector<int> v;
                //printf("asdf");
                for(int i=L;i<=H;i++){
                    if(arr[i]){
                        v.push_back(i);
                    }
                }
                for(int i=0;i<v.size()-1;i++){
                    printf("%d ",v[i]);
                }printf("%d\n",v[v.size()-1]);
            }else printf("-1\n");
        }
    }
    return 0;
}
