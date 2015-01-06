#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii AdjList;
map<int,int> mapper,reverseMapper;
int visited[101];
int startnode;
void dfs(int x){
    visited[x]++;
    for(int i=0;i<AdjList[x].size();i++){
        if(!visited[AdjList[x][i]]){
            dfs(AdjList[x][i]);
        }
    }

}

int main(void){
    int N,start,counter,numnode,num;
    vi unvisited;
    while(cin>>N && N){
        mapper.clear();
        reverseMapper.clear();
        AdjList.clear();
        AdjList.assign(N+1,vi());
        counter = 0;
        while(cin>>start){

            if(start){
                if(mapper.find(start)==mapper.end()){
                    mapper[start] = counter;
                    reverseMapper[counter] = start;
                    counter++;
                }

                while(cin>>num && num){
                    if(mapper.find(num)==mapper.end()){
                        mapper[num] = counter;
                        reverseMapper[counter] = num;
                        counter++;
                    }
                    AdjList[start].push_back(num);
                }

            }

            else{
                cin>>numnode;
                for(int i=0;i<numnode;i++){
                    unvisited.clear();
                    for(int j=0;j<=N;j++){
                        visited[j] = 0;
                    }
                    cin>>startnode;
                    visited[startnode] = -1;
                    dfs(startnode);

                    for(int j=1;j<=N;j++){
                        if(!visited[j]){
                            unvisited.push_back(j);
                        }
                    }
                    cout<<unvisited.size();
                    for(int j=0;j<unvisited.size();j++)
                        cout<<" "<<unvisited[j];
                    cout<<endl;
                }
                break;
            }
        }
    }

    return 0;
}
