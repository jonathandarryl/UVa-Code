#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef vector<int> vi;
int AdjList[50000];
int arr[50000];
vi topoSort;
void dfs(int u) {
    //printf(" %d", u);
    arr[u] = 1;

    int v = AdjList[u];
    if (arr[v] == 0)
    dfs(v);
    topoSort.push_back(u);
}

int main(void){
    int tc;
    scanf("%d",&tc);
    int casecounter = 1;
    //int arr[50000];
    while(tc--){
        topoSort.clear();
        int total = 0;
        int n;
        scanf("%d",&n);
        int fr,to;
        //AdjList.assign(n,vi());
        for(int i=0;i<n;i++){
            scanf("%d %d",&fr,&to);
            AdjList[fr-1] = to-1;
        }
        int maxi;
        memset(arr,0,sizeof arr);
        for(int i=0;i<n;i++){
            int temptot = 1;
            int now = i;

            //arr[i] = 1;
            //printf("NOW: %d\n",now);
            //printf("%d\n",i);
            if(arr[i]==0)
                dfs(i);
        }
        //for(int i=0;i<topoSort.size();i++)
          //  printf("%d ",topoSort[i]);
        printf("Case %d: %d\n",casecounter++,topoSort[topoSort.size()-1]+1);
    }

    return 0;
}
