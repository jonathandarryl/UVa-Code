#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int col, row,gold;
int danger[70][70];
char golds[70][70];
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};

void floodfill(int r, int c, char c1){
    if(golds[r][c]=='#' || golds[r][c]==c1)
        return;
    if(golds[r][c]=='G'){
        gold++;
        golds[r][c]=c1;
    }
    golds[r][c]=c1;
    if(danger[r][c])
        return;

    for(int i=0;i<4;i++)
        floodfill(r+dr[i],c+dc[i],c1);

}

int main(void){

    while(cin>>col>>row){
        getchar();
        gold = 0;
        for(int i=0;i<row;i++){
            gets(golds[i]);
        }

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                danger[i][j]=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(golds[i][j]=='T')
                    for(int d=0;d<4;d++)
                        danger[i+dr[d]][j+dc[d]]=1;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(golds[i][j]=='P'){
                    floodfill(i,j,'-');
                    break;
                }
        cout<<gold<<endl;


    }
    return 0;
}
