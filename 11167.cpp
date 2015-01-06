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


struct edge {
	int a, b, f, c;
	int ind;
};

const int inf = 1000 * 1000 * 1000;
const int MAXN = 1050;

int n, m;
vector <edge> e;
int pt[MAXN]; // very important performance trick
vector <int> g[MAXN];
long long flow = 0;
queue <int> q;
int d[MAXN];
int lim;

void add_edge(int a, int b, int c, int ind) {
	edge ed;

	//keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge

	ed.a = a; ed.b = b; ed.f = 0; ed.c = c; ed.ind = ind;
	g[a].push_back(e.size());
	e.push_back(ed);

	ed.a = b; ed.b = a; ed.f = c; ed.c = c; ed.ind = ind;
	g[b].push_back(e.size());
	e.push_back(ed);
}

bool bfs() {
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[1] = 0;
	q.push(1);
	while (!q.empty() && d[n] == inf) {
		int cur = q.front(); q.pop();
		for (size_t i = 0; i < g[cur].size(); i++) {
			int id = g[cur][i];
			int to = e[id].b;

			//printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);


			if (d[to] == inf && e[id].c - e[id].f >= lim) {
				d[to] = d[cur] + 1;
				q.push(to);
			}
		}
	}
	while (!q.empty())
		q.pop();
	return d[n] != inf;
}

bool dfs(int v, int flow) {
	if (flow == 0)
		return false;
	if (v == n) {
		//cout << v << endl;
		return true;
	}
	for (; pt[v] < g[v].size(); pt[v]++) {
		int id = g[v][pt[v]];
		int to = e[id].b;

		//printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);

		if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
			int pushed = dfs(to, flow);
			if (pushed) {
				e[id].f += flow;
				e[id ^ 1].f -= flow;
				return true;
			}
		}
	}
	return false;
}

void dinic() {
	for (lim = (1 << 30); lim >= 1;) {
		if (!bfs()) {
			lim >>= 1;
			continue;
		}

		for (int i = 1; i <= n; i++)
			pt[i] = 0;

		int pushed;

		while (pushed = dfs(1, lim)) {
			flow = flow + lim;
		}

		//cout << flow << endl;
	}
}

int main(void){
    int a,b;
    int water,dari[100],sampe[100];
    while(scanf("%d",&a)&&a){
        scanf("%d",&b);
        int mini, maxi;
        mini = INF;
        maxi = -1;
        FOR(i,a){
            scanf("%d %d %d",&water,&dari[i],&sampe[i]);
            maxi = max(sampe[i],maxi);
            mini = min(mini,dari[i]);
            add_edge(i*2,i*2+1,water,i);
        }
        int cur = a*2;
        int time0 = cur;
        REP(i,mini,maxi){
            add_edge(cur,cur+1,m,i);
            cur+=2;
        }
        int ctr = 0;
        REPN(i,mini+1,maxi){
            add_edge(time0+ctr,cur+1,INF,i);
            ctr++;
        }

        FOR(i,a){
            REP(j,dari[i],sampe[i]){
                add_edge(i*2+1,dari[i]-mini+time0,1,i);
            }
        }

        dinic();

        cout<<flow<<endl;

    }
}
