#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
bool painted[100][100];
char grid[100][100];
int dr[]={0,-1,0,1};
int dc[]={-1,0,1,0};

void floodfill(int row, int col, char c1){
    if(row<0 || col<0)  return;
    if(grid[row][col]=='X' || grid[row][col]=='\0') return;
    if(painted[row][col])   return;
    grid[row][col] = c1;
    painted[row][col]= true;
    for(int i=0;i<4;i++)
        floodfill(row+dr[i],col+dc[i],c1);

}

int main(void){
    int counter;
    int testcase;
    cin>>testcase;
    getchar();
    while(testcase--){
        counter = 0;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                painted[i][j] = false;
        while(gets(grid[counter++])){
            if(grid[counter-1][0]=='_')
                break;
        }
        for(int i=0;i<counter-1;i++)
            for(int j=0;grid[i][j]!='\0';j++)
                if(grid[i][j]=='*')
                    floodfill(i,j,'#');
        for(int i=0;i<counter;i++){
            printf("%s\n",grid[i]);

        }

    }
    return 0;
}
