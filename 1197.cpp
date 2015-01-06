#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> vi;

int main(void){

    vector<vi> AdjList;
    int n,m;
    int flag[30000];
    int sus[30000];
    while(cin>>n>>m &&(n || m)){
        AdjList.assign(n,vi());
        for(int i=0;i<n;i++)
            flag[i] = 0;
        for(int i=0;i<m;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
                cin>>sus[j];
            for(int j=0;j<k;j++){
                int temp = sus[0];
                sus[0] = sus[j];
                sus[j] = temp;
                for(int l=1;l<k;l++){
                    AdjList[sus[0]].push_back(sus[l]);
                }
            }

        }
        int counter = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){

            int u = q.front();
            q.pop();
            if(!flag[u]){
                for(int j=0;j<(int)AdjList[u].size();j++){
                    if(!flag[AdjList[u][j]]){
                        q.push(AdjList[u][j]);
                    }
                }
                flag[u] = 1;
                counter++;
            }
        }
        printf("%d\n",counter);


    }
    return 0;
}
