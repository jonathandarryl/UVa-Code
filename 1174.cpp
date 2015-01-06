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

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define pb push_back
#define TC(tc) while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))

vi taken;
priority_queue<ii>pq;
vector<vii> AdjList;
void process(int vtx) {    // so, we use -ve sign to reverse the sort order
  taken[vtx] = 1;
  for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
    ii v = AdjList[vtx][j];
    if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
} }



int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    string name,name2;
    int V,route,cost;
    map<string,int>mapper;
    scanf("%d",&tc);
    //int mst_cost;
    TC(tc){
        scanf("%d %d",&V,&route);
        AdjList.assign(V,vii());
        int counter = 0;
        mapper.clear();
        for(int i=0;i<route;i++){
            cin>>name>>name2>>cost;
            if(mapper.find(name)==mapper.end()){
                mapper[name] = counter++;
            }
            if(mapper.find(name2)==mapper.end())
                mapper[name2] = counter++;
            AdjList[mapper[name]].push_back(ii(mapper[name2],cost));
            AdjList[mapper[name2]].push_back(ii(mapper[name],cost));
        }
        int u,w;
        taken.assign(V, 0);                // no vertex is taken at the beginning
        process(mapper[name]);   // take vertex 0 and process all edges incident to vertex 0
        int mst_cost = 0;
        while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            u = -front.second, w = -front.first;  // negate the id and weight again
            if (!taken[u])                 // we have not connected this vertex yet
                mst_cost += w, process(u); // take u, process all edges incident to u
        }
        printf("%d\n",mst_cost);
        if(tc)printf("\n");
    }

    return 0;
}
