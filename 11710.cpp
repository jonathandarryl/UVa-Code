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
    int town, route;
    string name, name2;
    map<string,int>mapper;
    while(scanf("%d%d",&town,&route) && (town || route)){
        mapper.clear();
        int counter = 0;
        AdjList.assign(town,vii());
        for(int i=0;i<town;i++){
            cin>>name;
            mapper[name] = counter++;
        }
        int dist;
        for(int i=0;i<route;i++){
            cin>>name>>name2;
            scanf("%d",&dist);
            AdjList[mapper[name]].push_back(ii(mapper[name2],dist));
            AdjList[mapper[name2]].push_back(ii(mapper[name],dist));
        }
        int u,w;
        cin>>name;
        taken.assign(town, 0);                // no vertex is taken at the beginning
        process(mapper[name]);   // take vertex 0 and process all edges incident to vertex 0
        int mst_cost = 0;
        while (!pq.empty()) {  // repeat until V vertices (E=V-1 edges) are taken
            ii front = pq.top(); pq.pop();
            u = -front.second, w = -front.first;  // negate the id and weight again
            if (!taken[u])                 // we have not connected this vertex yet
                mst_cost += w, process(u); // take u, process all edges incident to u
        }                                        // each edge is in pq only once!
        bool valid = true;
        for(int i=0;i<taken.size();i++){
            if(taken[i]==0){
                valid = false;
                break;
            }
        }
        if(valid){
            printf("%d\n",mst_cost);
        }
        else printf("Impossible\n");
    }





    return 0;
}

