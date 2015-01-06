#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main(void){
    int dx[]={0,-1,0,1,0,0};
    int dy[]={-1,0,1,0,0,0};
    int dz[]={0,0,0,0,-1,1};
    int l,r,c,x,y,z,x1,y1,z1;
    char mapper[31][31][31];
    int value[31][31][31];
    while(cin>>l>>r>>c && (l||r||c)){
        for(int i=0;i<l;i++)
            for(int j=0;j<r;j++)
                for(int k=0;k<c;k++){
                    value[i][j][k] = -1;
                    cin>>mapper[i][j][k];
                    if(mapper[i][j][k]=='S'){
                        z=i,x=j,y=k;
                        value[i][j][k] = 0;
                    }
                    else if(mapper[i][j][k]=='E')
                        z1=i,x1=j,y1=k;
                }
        queue<int> q1,q2,q3;
        q1.push(x);
        q2.push(y);
        q3.push(z);
        bool found = false;
        while(!q1.empty()){
            int x2 = q1.front(); q1.pop();
            int y2 = q2.front(); q2.pop();
            int z2 = q3.front(); q3.pop();
            for(int i=0;i<6;i++){
                int xdest = x2+dx[i];
                int ydest = y2+dy[i];
                int zdest = z2+dz[i];
                if(xdest>=0 && xdest<r && ydest>=0 && ydest<c && zdest>=0 && zdest<l && mapper[zdest][xdest][ydest]!='#'){
                    value[zdest][xdest][ydest] = value[z2][x2][y2]+1;
                    if(xdest == x1 && ydest == y1 && zdest == z1){
                        found = true;
                        break;
                    }
                    mapper[zdest][xdest][ydest] = '#';
                    q1.push(xdest);
                    q2.push(ydest);
                    q3.push(zdest);
                }
            }
            if(found)
                break;
        }
        if(found)
            printf("Escaped in %d minute(s).\n",value[z1][x1][y1]);
        else
            printf("Trapped!\n");
    }
    return 0;
}
