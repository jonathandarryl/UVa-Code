#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main(void){
    int dr[] = {0,-1,0,1};
    int dc[] = {-1,0,1,0};
    int TC,R,C,x,y;
    queue<int> q1,q2;
    char mapper[1001][1001];
    int time[1001][1001];
    scanf("%d",&TC);
    while(TC--){
        scanf("%d %d",&R,&C);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                cin>>mapper[i][j];
                time[i][j] = 10000000;
                if(mapper[i][j]=='F'){
                    time[i][j] = 0;
                    q1.push(i);
                    q2.push(j);
                }
                else if(mapper[i][j]=='J')
                    x = i,y = j;
            }
        while(!q1.empty()){
            int x1 = q1.front(); q1.pop();
            int y1 = q2.front(); q2.pop();
            for(int i=0;i<4;i++){
                int x2 = x1+dr[i];
                int y2 = y1+dc[i];
                if(x2>=0 && x2<R && y2>=0 && y2<C && mapper[x2][y2]!='#' && time[x2][y2]>time[x1][y1]+1){
                    time[x2][y2] = time[x1][y1]+1;
                    q1.push(x2);
                    q2.push(y2);
                }
            }
        }

    }
    return 0;
}
