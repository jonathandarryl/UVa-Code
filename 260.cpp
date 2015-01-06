#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int dr[] = {-1,0,1,-1,0,1};
int dc[] = {-1,-1,0,0,1,1};
char grid[210][210];
int input;
bool white;

void floodfill(int row, int col, char c1, char c2){
    if(row<0||row>=input||col<0||col>=input)    return;
    if(grid[row][col]!=c1)  return;
    grid[row][col]=c2;
    for(int d=0;d<6;d++)
        floodfill(row+dr[d],col+dc[d],c1,c2);

}
int main(void){
    int prob=1;
    while(cin>>input && input){
        getchar();
        for(int i=0;i<input;i++)
            gets(grid[i]);
        white = false;
        for(int i=0;i<input;i++)
            if(grid[i][0]=='w')
                floodfill(i,0,'w','.');
        for(int i=0;i<input;i++)
            if(grid[i][input-1]=='.'){
                white = true;
                break;
            }
        cout<<prob++<<" ";
        if(white)
            cout<<"W"<<endl;
        else
            cout<<"B"<<endl;
    }
    return 0;
}
