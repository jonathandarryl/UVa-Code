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

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int,ii> pii;
#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC() while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    int arr[1000][1000];
    scanf("%d",&tc);
    TC(){
        int row, col;
        scanf("%d %d",&row,&col);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                scanf("%d",&arr[i][j]);
        int V = row*col;
        vi dist(V, INF); dist[0] = arr[0][0];                    // INF = 1B to avoid overflow , ii(weight,node).
        priority_queue< pii, vector< pii>, greater<pii> > pq; pq.push(pii(dist[0],ii(0, 0)));
                 // ^to sort the pairs by increasing distance from s
        while (!pq.empty()) {                                             // main loop
        pii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
        int d = front.first, u = front.second.first*col + front.second.second;
        if (d > dist[u]) continue;   // this check is important, see the explanation
        int x = front.second.first, y = front.second.second;
        for (int j = 0; j < 4; j++) {
        int x2 = x+dx[j], y2 = y+dy[j];                       // all outgoing edges from u
        if(x2>=0 && x2 < row && y2 >= 0 && y2 < col){
        int comb = x2*col + y2;
        if (dist[u] + arr[x2][y2] < dist[comb]) {
            dist[x2*col + y2] = dist[u] + arr[x2][y2];                 // relax operation
            pq.push(pii(dist[comb], ii(x2,y2)));
        } } } } // note: this variant can cause duplicate items in the priority queue

        printf("%d\n",dist[(row-1)*col + col-1]);
    }
    return 0;
}
