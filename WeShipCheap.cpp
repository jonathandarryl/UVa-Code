#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<stdio.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

map<int,int> dist;
map<string, int> mapper;
map<int, string> reverseMapper;
vector<vii> AdjList;
map<int, int> p;
vector<int> res;
void printPath(int u, int s){
    if(u==s){
        res.push_back(s);
        return;
    }
    printPath(p[u],s);
    res.push_back(u);
}

void clearing(){
    mapper.clear();
    dist.clear();
    reverseMapper.clear();
    p.clear();
    res.clear();
}

int main(void){
    int route,counter;
    string from,to;
    bool first = true;
    while(cin>>route){
        counter = 0;
        clearing();
        if(first)
            first = false;
        else
            cout<<endl;
        AdjList.assign(route*2,vii());
        for(int i=0;i<route;i++){
            cin>>from;
            cin>>to;
            //cout<<i<<endl;
            if(mapper.find(from)==mapper.end()){
                mapper[from] = counter;
                reverseMapper[counter] = from;
                counter++;
            }
            //cout<<i<<endl;
            if(mapper.find(to) == mapper.end()) {
                mapper[to] = counter;
                reverseMapper[counter] = to;
                counter++;
            }

            AdjList[mapper[from]].push_back(ii(mapper[to], 0));
            AdjList[mapper[to]].push_back(ii(mapper[from], 0));
            //cout<<i<<endl;
        }
        //cout<<4;
        cin>>from>>to;
        if(mapper.find(from)==mapper.end() || mapper.find(to)==mapper.end())
            cout<<"No route"<<endl;
        else{
            int s = mapper[from];
            queue<int> q;
            q.push(s);
            dist[s] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int j=0;j<(int)AdjList[u].size();j++){
                    ii v = AdjList[u][j];
                    if(!dist.count(v.first)){
                        dist[v.first] = dist[u] + 1;
                        p[v.first] = u;
                        q.push(v.first);
                    }
                }
            }
            if(dist[mapper[to]]){
                printPath(mapper[to],mapper[from]);
                cout<<reverseMapper[res[0]]<<" ";
                for(int i=1;i<res.size()-1;i++)
                    cout<<reverseMapper[res[i]]<<endl<<reverseMapper[res[i]]<<" ";
                cout<<reverseMapper[res[res.size()-1]]<<endl;
            }
            else
                cout<<"No route"<<endl;
        }
    }
    return 0;
}


