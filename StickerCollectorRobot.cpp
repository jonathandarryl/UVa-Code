#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(void){
    int row, col, command, rownow, colnow, countsticker;
    char com[51000];
    char field[101][101];
    char now;
    while(scanf("%d %d %d",&row,&col,&command) && row && col && command){
        getchar();
        for(int i=0;i<row;i++)
            gets(field[i]);
        gets(com);
        countsticker = 0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(field[i][j]=='N'){
                    now = 'N';
                    rownow = i;
                    colnow = j;
                    break;
                }
                else if(field[i][j]=='S'){
                    now = 'S';
                    rownow = i;
                    colnow = j;
                    break;
                }
                else if(field[i][j]=='L'){
                    now = 'L';
                    rownow = i;
                    colnow = j;
                    break;
                }
                else if(field[i][j]=='O'){
                    now = 'O';
                    rownow = i;
                    colnow = j;
                    break;
                }
        for(int i=0;i<command;i++)
            switch(com[i]){
                case 'D':{
                    if(now=='N')
                        now = 'L';
                    else if(now=='L')
                        now = 'S';
                    else if(now=='O')
                        now = 'N';
                    else if(now=='S')
                        now = 'O';
                    break;
                }
                case 'E':{
                    if(now=='N')
                        now = 'O';
                    else if(now=='L')
                        now = 'N';
                    else if(now=='O')
                        now = 'S';
                    else if(now=='S')
                        now = 'L';
                    break;
                }
                case 'F':{
                    if(now=='N' && rownow!=0){
                        rownow--;
                        if(field[rownow][colnow]=='#')
                            rownow++;
                        if(field[rownow][colnow]=='*'){
                            countsticker++;
                            field[rownow][colnow]='.';
                        }
                    }
                    else if(now=='L' && colnow!=col-1){
                        colnow++;
                        if(field[rownow][colnow]=='#')
                            colnow--;
                        if(field[rownow][colnow]=='*'){
                            countsticker++;
                            field[rownow][colnow]='.';
                        }
                    }
                    else if(now=='S' && rownow!=row-1){
                        rownow++;
                        if(field[rownow][colnow]=='#')
                            rownow--;
                        if(field[rownow][colnow]=='*'){
                            countsticker++;
                            field[rownow][colnow]='.';
                        }
                    }
                    else if(now=='O' && colnow!=0){
                        colnow--;
                        if(field[rownow][colnow]=='#')
                            colnow++;
                        if(field[rownow][colnow]=='*'){
                            countsticker++;
                            field[rownow][colnow]='.';
                        }
                    }
                    break;
                }
            }
        cout<<countsticker<<endl;
    }
    return 0;
}
