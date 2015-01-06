
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<set>
#include<bitset>
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
#endif

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define MAX_N 10010
#define LOG_TWO_N 16

class SegmentTree{
	private: vi st, A;
	int n;
	int left(int p){return p<<1;}
	int right(int p){return (p<<1)+1;}
	void build(int p, int L, int R){
		if(L==R)
			st[p] = L;
		else{
			build(left(p), L, (L+R)/2);
			build(right(p), (L+R)/2+1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2])?p1:p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j){
		if(i>R || j<L) return -1;
		if(L>=i && R<=j) return st[p];
		int p1 = rmq(left(p), L, (L+R)/2, i, j);
		int p2 = rmq(right(p), (L+R)/2+1, R, i,j);
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (A[p1]<=A[p2]) ? p1:p2;
	}
	public:
	SegmentTree(const vi &_A){
		A = _A; n = (int) A.size();
		st.assign(4*n,0);
		build(1,0,n-1);
	}
	int rmq(int i, int j){
		return rmq(1,0,n-1,i,j);
	}
};

int L[4*MAX_N], E[4*MAX_N], H[MAX_N], idx;
bool visited[MAX_N];
vector<vi>children;
void dfs(int cur, int depth){
	H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	visited[cur] = true;
	//printf("now: %d\n",cur);
	//printf("
	for(int i=0;i<(int)children[cur].size();i++){
		if(!visited[children[cur][i]])
		{
			dfs(children[cur][i], depth+1);

		}E[idx] = cur;
			L[idx++] = depth;
	}
}

void buildRMQ(){
	idx = 0;
	memset(H,-1, sizeof H);
	reset(L,-1);
	reset(E,-1);
	memset(visited,false,sizeof visited);
	dfs(0,0);
}


int main(void){
	//freopen("in.txt","r",stdin);
	int V;
	while(scanf("%d",&V),V){
        int fr, to;
        children.assign(V,vi());
        FOR(i,V-1){
            scanf("%d %d\n",&fr,&to);
            children[fr].pb(to);
            children[to].pb(fr);
        }
        buildRMQ();
        //int counter = 0;
        int query;
        scanf("%d",&query);
        vi _L;
        FOR(i,idx){
            //printf("%d ",E[i]);
            _L.pb(L[i]);
        }//printf("\n");
        SegmentTree st = SegmentTree(_L);
        /*FOR(i,idx){
            printf("%d ",H[i]);
        }printf("\n");*/
        /*FOR(i,(int)_E.size()){
                REP(j,i,(int)_E.size()){
                    printf("%d\n",st.rmq(H[i],H[j]));
                }
        }*/
        map<ii,int> mapper;
        FOR(i,query){
            scanf("%d %d",&fr, &to);
            if(H[fr]>H[to]){
                int temp = fr;
                fr = to;
                to = temp;
            }

            int LCA = E[st.rmq(H[fr],H[to])];
            int dist = L[H[fr]] + L[H[to]] - 2*L[H[LCA]];
            if(dist %2 == 0){
                printf("The fleas meet at %d.\n");
            }else{
                printf("The fleas jump forever between %d and %d.\n");
            }
	}
	return 0;
}
