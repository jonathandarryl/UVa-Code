#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char dice[100][100];
int maxrow, maxcol;
int dr[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};
void scan(){
    getchar();
    for(int i=0;i<maxrow;i++)
        gets(dice[i]);
}
void filldice(int row, int col, char c1, char c2){
    if(row<0 || row>=maxrow || col<0 || col>=maxcol)    return;
    if(dice[row][col]!=c1)  return;
    dice[row][col]=c2;
    for(int d=0;d<4;d++)    filldice(row+dr[d],col+dc[d],c1,c2);
}

int floodfill(int row, int col, char c1, char c2){
    if(row<0 || row>=maxrow || col<0 || col>=maxcol)    return 0;
    int ans = 0;
    if(dice[row][col]=='X') {
        filldice(row,col,'X','*');
        ans++;
    }
    if(dice[row][col]!=c1) return 0;
    dice[row][col] = c2;
    for(int d=0;d<4;d++)    ans+=floodfill(row+dr[d],col+dc[d],c1,c2);
    return ans;
}



int main(void){
    int counter, countthrow = 1;
    int die[1000];
    while(cin>>maxcol>>maxrow && maxrow && maxcol){
        scan();
        counter = 0;
        for(int i=0;i<maxrow;i++)
            for(int j=0;j<maxcol;j++){
                if(dice[i][j]!='.'){
                    die[counter] = floodfill(i,j,'*','.');
                    counter++;
                }
            }
        sort(die,die+counter);
        cout<<"Throw "<<countthrow++<<endl;
        for(int i=0;i<counter-1;i++)
            cout<<die[i]<<" ";
        cout<<die[counter-1]<<endl<<endl;

    }
    return 0;
}
