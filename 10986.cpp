#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<queue>
#define INF 10000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int main(void){
    int tc,N,counter,edge,len,from,to,realfrom,realto;
    map<int,int> mapper;
    cin>>tc;
    vector<vii> AdjList;
        for(int z=1;z<=tc;z++){
        mapper.clear();
        counter = 0;
        cin>>N>>edge>>realfrom>>realto;
        AdjList.assign(N,vii());
        vi dist(N,INF);
        for(int i=0;i<edge;i++){
            cin>>from>>to>>len;
            if(mapper.find(from)==mapper.end())
                mapper[from] = counter++;
            if(mapper.find(to) == mapper.end())
                mapper[to] = counter++;
            AdjList[mapper[from]].push_back(ii(mapper[to],len));
            AdjList[mapper[to]].push_back(ii(mapper[from],len));
        }
        int s;
        s = mapper[realfrom];
        dist[s] = 0;
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
        while(!pq.empty()){
            ii front = pq.top(); pq.pop();
            int d = front.first;
            int u = front.second;
            if(d == dist[u]){
                for(int j=0;j<(int)AdjList[u].size();j++){
                    ii v = AdjList[u][j];
                    if(dist[u] + v.second < dist[v.first]){
                        dist[v.first] = dist[u] + v.second;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
            }
        }
        printf("Case #%d: ",z);
        if(dist[mapper[realto]]==INF || edge == 0)
            printf("unreachable\n");
        else
            printf("%d\n",dist[mapper[realto]]);
    }
    return 0;
}
