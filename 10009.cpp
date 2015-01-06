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
map<char, int> mapper;
map<int, char> reverseMapper;
vector<vii> AdjList;
map<int, int> p;
vector<int> res;

void clearing(){
    mapper.clear();
    dist.clear();
    reverseMapper.clear();
    p.clear();
    res.clear();
}

void printPath(int u, int s){
    if(u==s){
        cout<<reverseMapper[u];
        return;
    }
    printPath(p[u],s);
    cout<<reverseMapper[u];
}

int main(void){
    int test;
    cin>>test;
    while(test--){
        clearing();
        int counter = 0;
        int numroad,question;
        cin>>numroad>>question;
        AdjList.assign(numroad*2,vii());
        string from,to;
        char fromc,toc;
        for(int i=0;i<numroad;i++){
            cin>>from>>to;
            fromc = from.at(0);
            toc = to.at(0);
            if(mapper.find(fromc)==mapper.end()){
                mapper[fromc] = counter;
                reverseMapper[counter++] = fromc;
            }

            if(mapper.find(toc) == mapper.end()) {
                mapper[toc] = counter;
                reverseMapper[counter++] = toc;
            }

            AdjList[mapper[fromc]].push_back(ii(mapper[toc], 0));
            AdjList[mapper[toc]].push_back(ii(mapper[fromc], 0));
        }
        for(int i=0;i<question;i++){
            cin>>from>>to;
            fromc = from.at(0);
            toc = to.at(0);
            dist.clear();
            p.clear();
            int s = mapper[fromc];
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
            printPath(mapper[toc],mapper[fromc]);
            cout<<endl;
        }
        if(test)
            cout<<endl;
    }

}
