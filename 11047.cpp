
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
#define TC() while(tc--)
#define reset(a,b) memset(a,b,sizeof(a))
int p[110][110];
string name,fr,to;
map<string,int> mapper;
map<int,string> rev;
void printPath(int i, int j){
    if(i!=j)printPath(i,p[i][j]);
    if(j == mapper[fr])cout<<rev[j];
    else cout<<" "<<rev[j];
}
int main(void){
    //freopen("in.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    int dist[110][110];

    TC(){
        int V;
        mapper.clear();
        rev.clear();
        string str;
        scanf("%d",&V);
        for(int i=0;i<V;i++){
            cin>>str;
            mapper[str] = i;
            rev[i] = str;
        }
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++){
                scanf("%d",&dist[i][j]);
                dist[i][j] = (dist[i][j]==-1?INF:dist[i][j]);
                p[i][j] = i;
            }
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
              for (int j = 0; j < V; j++)
                 if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    p[i][j] = p[k][j];
                 }
        int Q;
        scanf("%d",&Q);

        for(int i=0;i<Q;i++){
            cin>>name>>fr>>to;
            if(dist[mapper[fr]][mapper[to]] == INF){
                cout<<"Sorry Mr "<<name<<" you can not go from "<<fr<<" to "<<to<<endl;
            }
            else{
                cout<<"Mr "<<name<<" to go from "<<fr<<" to "<<to<<", you will receive "<<dist[mapper[fr]][mapper[to]]<<" euros"<<endl;
                if(fr==to)
                    cout<<"Path:"<<fr<<" "<<fr<<endl;
                else{
                    printf("Path:");
                    printPath(mapper[fr],mapper[to]);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
