#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

int AdjMat[101][101];
int visited;
int dr[] = {0,-1,0,1};
int dc[] = {-1,0,1,0};
int dimension;
void bfs(int row, int col,int intended){
    if(!row||!col||row>dimension||col>dimension) return;
    if(AdjMat[row][col]==-1 || AdjMat[row][col]!=intended) return;
    visited++;
    AdjMat[row][col] = -1;
    for(int i=0;i<4;i++)
        bfs(row+dr[i],col+dc[i],intended);
}

int main(void){
    int x,y;
    while(cin>>dimension && dimension){
        bool notgood = false;
        for(int i=0;i<=dimension;i++)
            for(int j=0;j<=dimension;j++)
                AdjMat[i][j] = 0;
        for(int i=1;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                cin>>x>>y;
                AdjMat[x][y] = i;
            }
        }
        for(int i=0;i<dimension;i++){
            for(int j=1;j<=dimension;j++){
                for(int k=1;k<=dimension;k++){
                    if(AdjMat[j][k]!=-1){
                        visited = 0;
                        bfs(j,k,AdjMat[j][k]);
                        if(visited % dimension!=0){
                            notgood = true;
                            break;
                        }
                    }
                }
                if(notgood)
                    break;
            }
            if(notgood)
                break;
        }
        if(notgood)
            cout<<"wrong"<<endl;
        else
            cout<<"good"<<endl;

    }
    return 0;
}
