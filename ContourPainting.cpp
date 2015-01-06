#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

char grid[100][100];
int painted[100][100];
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};
int counter;
void floodfill(int row, int col, char c1){
    if(row<0||col<0||row>=counter-1||col>=80 || painted[row][col])
        return;
    if(grid[row][col]=='X'){
        painted[row][col]=1;
        return;
    }
    if(row-1>=0 && grid[row-1][col]=='X'){
        grid[row][col]='#';
        painted[row][col] = 1;
    }
    if(col-1>=0 && grid[row][col-1]=='X'){
        grid[row][col]='#';
        painted[row][col] = 1;
    }
    if(row+1<counter-1 && grid[row+1][col]=='X'){
        grid[row][col]='#';
        painted[row][col] = 1;
    }
    if(col+1<100 && grid[row][col+1]=='X'){
        grid[row][col]='#';
        painted[row][col] = 1;
    }
    painted[row][col]=1;
    for(int d=0;d<4;d++)
        floodfill(row+dr[d],col+dc[d],c1);

}

int main(void){
    int test;
    cin>>test;
    getchar();
    for(int i=0;i<test;i++){
        counter = 0;
        while(true){
            gets(grid[counter]);
            counter++;
            if(grid[counter-1][0]=='_')
                break;
        }
        for(int i=0;i<counter-1;i++)
            for(int j=strlen(grid[i]);j<=80;j++)
                grid[i][j]=' ';
        for(int i=0;i<counter;i++)
            for(int j=0;j<100;j++)
                painted[i][j]=0;
        for(int i=0;i<counter-1;i++)
            for(int j=0;j<strlen(grid[i]);j++)
                if(grid[i][j]=='*'){
                    grid[i][j]=' ';
                    floodfill(i,j,'#');
                }
        int last;
        for(int i=0;i<counter-1;i++){
            last = 0;
            for(int j=0;j<80;j++)
                if(grid[i][j]=='#' || grid[i][j]=='X')
                    last = j;
            if(last||grid[i][0]=='#'||grid[i][0]=='X')
                grid[i][last+1]='\0';
            else
                grid[i][0]='\0';
        }
        for(int i=0;i<counter;i++)
            printf("%s\n",grid[i]);
    }
    return 0;
}
