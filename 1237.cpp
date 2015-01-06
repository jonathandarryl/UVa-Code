//Template for Dev-C++ 5.3.0.4 by unlimitedsky
#include<iostream>
#include<cstdio>
#include<string>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<utility>
using namespace std;
#define FOR(i,a,b,c) for (int i = a; i <= b; i+=c)
#define FORR(i,a,b,c) for (int i = a; i >= b; i-=c)
#define INC(i,a,b) for (int i = a; i <= b; i++)
#define DEC(i,a,b) for (int i = a; i >= b; i--)
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define reset(a,b) memset(a,b,sizeof a)
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<PII> vii;

int tc, n, q, a;
map<string,PII>car;
char dummy;
string str, ans;

int main(){
	scanf("%d", &tc);
	while(tc--){
		car.clear();
		scanf("%d", &n);
		while(n--){
			cin >> str;
			int x,y;
			scanf("%d %d", &x, &y);
            car[str] = PII(x,y);
		}
		scanf("%d", &q);
		while(q--){
			ans = "----";
			scanf("%d", &a);
			for (map<string,PII>::iterator it = car.begin(); it!=car.end(); ++it){
                    PII ii = it->second;
				if (a >= ii.fi && a <= ii.se){
					if (ans == "----") ans = it->fi;
					else{
						ans = "----";
						break;
					}
				}
			}
			if (ans != "----") cout << ans << endl;
			else printf("UNDETERMINED\n");
		}
		if (tc) printf("\n");
	}

	return 0;
}
