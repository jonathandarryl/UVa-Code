#include<iostream>
#include<stdio.h>
#include<queue>
#include<map>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
map<int,int> mapper;
map<int,int> dist;
map<int,int> boom;
int main(void){
    int numpeople,counter = 0,num,neigh;
    scanf("%d",&numpeople);
    AdjList.assign(numpeople,vii());
    for(int i=0;i<numpeople;i++){
        if(mapper.find(i)==mapper.end())
            mapper[i] = counter++;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&neigh);
            if(mapper.find(neigh)==mapper.end())
                mapper[neigh] = counter++;
            AdjList[mapper[i]].push_back(ii(mapper[neigh], 0));
        }
    }
    int test,fp;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&fp);
        if(AdjList[mapper[fp]].size()==0)
            printf("0\n");
        else{
            int maxi = 0, day;
            ii v;
            dist.clear();
            boom.clear();
            dist[mapper[fp]] = 0;
            queue<int> q;
            q.push(mapper[fp]);
            while(!q.empty()){
                int u = q.front();q.pop();
                for(int j=0;j<(int)AdjList[u].size();j++){
                    v = AdjList[u][j];
                    if(!dist.count(v.first)){
                        dist[v.first] = dist[u] + 1;
                        boom[dist[v.first]]++;
                        q.push(v.first);
                    }
                }
                if(maxi<boom[dist[v.first]]){
                    maxi = boom[dist[v.first]];
                    day = dist[v.first];
                }
            }
            //for(map<int,int>::iterator it = boom.begin();it!=boom.end();it++)
                //printf("%d %d\n",it->first,it->second);
            printf("%d %d\n",maxi, day);
        }
    }
    return 0;
}
