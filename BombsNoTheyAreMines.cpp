#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef pair<int,int> ii;

int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};


int main(void){
    int row,col,startx,starty,endx,endy;
    map<ii,int> step;
    while(scanf("%d %d",&row,&col) && row && col){
        int rowmine,numrow,nummine,mine;
        scanf("%d",&rowmine);
        bool grid[1001][1001];
        for(int i=0;i<rowmine;i++){
            scanf("%d %d",&numrow,&nummine);
            for(int j=0;j<nummine;j++){
                scanf("%d",&mine);
                grid[numrow][mine] = true;
            }
        }
        scanf("%d %d",&startx,&starty);
        scanf("%d %d",&endx,&endy);
        step.clear();
        queue<int> qr,qc;
        step[ii(startx,starty)] = 1;
        qr.push(startx);
        qc.push(starty);

        while(!qr.empty()){
            int currow,curcol;
            currow = qr.front();curcol = qc.front();
            qr.pop(); qc.pop();
            for(int i=0;i<4;i++){
                int curx = currow+dr[i], cury = curcol+dc[i];
                if(curx<row && cury<col && curx>=0 && cury>=0 && !step[ii(curx,cury)] && !grid[curx][cury]){
                    step[ii(curx,cury)] = step[ii(currow,curcol)]+1;
                    qr.push(curx);
                    qc.push(cury);
                }
            }
            if(!step[ii(endx,endy)])
                break;
        }
        printf("%d\n",step[ii(endx,endy)]-1);
    }
    return 0;
}
