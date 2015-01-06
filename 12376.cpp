#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int>vi;
typedef vector<vi> vii;

int main(void){
    int tc,n,m,casecounter = 1;
    int arr[120];
    scanf("%d",&tc);
    vector<vi> AdjList;
    while(tc--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        AdjList.assign(n,vi());
        int fr,to;
        for(int i=0;i<m;i++){
            scanf("%d %d",&fr,&to);
            AdjList[fr].push_back(to);
        }
        int now = arr[0], total = 0;
        int temp, maxlearn;
        while(true){
            int maxlearn = 0;
            if(AdjList[now].size() == 0) break;
            for(int i=0;i<AdjList[now].size();i++)
                if(arr[AdjList[now][i]]>maxlearn){
                    maxlearn = arr[AdjList[now][i]];
                    temp = AdjList[now][i];
                }
            now = temp;
            total+=maxlearn;
            //printf("%d\n",total);
        }
        printf("Case %d: %d %d\n",casecounter++,total,now);

    }

    return 0;
}
