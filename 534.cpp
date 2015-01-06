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

int main(void){
    //freopen("in.txt","r",stdin);

    int V, x[202],y[202];
    double AdjMatrix[300][300];
    int casecounter = 1;
    while(scanf("%d",&V) && V){
        //printf("V = %d\n",V);
        for(int i=0;i<V;i++){
            AdjMatrix[i][i] = 0;
        //printf("%d\n",i);
            scanf("%d %d",&x[i], &y[i]);
        }

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++)
                AdjMatrix[i][j] = AdjMatrix[j][i] = hypot((x[i]-x[j]),(y[i]-y[j]));
        }


        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    AdjMatrix[i][j] = min(AdjMatrix[i][j], max(AdjMatrix[i][k], AdjMatrix[k][j]));
        printf("Scenario #%d\n",casecounter++);
        printf("Frog Distance = %.3lf\n\n",AdjMatrix[0][1]);

    }

    return 0;
}
