#include<stdio.h>
#include<map>
#include<queue>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(void){
    int test;
    scanf("%d",&test);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for(int z=1;z<=test;z++){
        printf("DATA SET  %d\n\n",z);
        map<string,int> mapper;
        mapper.clear();
        vector<vii> AdjList;
        AdjList.clear();
        string in,fr,to;
        int numwarehouse, numroute, numquery,counter = 0;
        scanf("%d %d %d",&numwarehouse,&numroute, &numquery);
        AdjList.assign(numwarehouse,vii());
        for(int i=0;i<numwarehouse;i++){
            cin>>in;
            mapper[in] = counter++;
        }
        while(numroute--){
            cin>>fr>>to;
            AdjList[mapper[fr]].push_back(ii(mapper[to],0));
            AdjList[mapper[to]].push_back(ii(mapper[fr],0));
        }
        while(numquery--){
            int size;
            scanf("%d",&size);
            cin>>fr>>to;
            queue<int> q;
            map<int,int> dist;
            dist.clear();
            dist[mapper[fr]] = 1;
            q.push(mapper[fr]);
            while(!q.empty()){
                int u = q.front();q.pop();
                for(int i=0;i<(int) AdjList[u].size();i++){
                    ii v = AdjList[u][i];
                    if(!dist.count(v.first)){
                        dist[v.first] = dist[u]+1;
                        q.push(v.first);
                    }
                }
            }
            dist[mapper[to]]--;
            if(dist[mapper[to]]==-1)
                printf("NO SHIPMENT POSSIBLE\n");
            else
                printf("$%d\n",dist[mapper[to]]*size*100);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
