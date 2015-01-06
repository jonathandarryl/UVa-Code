#include <stdio.h>
#include <string.h>
#define MINE '1'   // a mine-filled cell
#define FREE '0'   // a mine-free cell
#define MAX_ROWS 101  // maximum rows of a minefield
#define MAX_COLS 100  // maximum columns of a minefield
#include<iostream>
using namespace std;
void scan_minefield(char [][MAX_COLS+1], int, int);
void count_minefield(char [][MAX_COLS+1], int, int);
int goldcounter;
int main(void)
{
	char minefield[MAX_ROWS][MAX_COLS+1];
	int row_size, col_size; // actual size of minefield read
    int counter,i,j;
    int count = 1;
    while(scanf("%d %d",&col_size,&row_size) == 2){
        scan_minefield(minefield,row_size,col_size);
        goldcounter = 0;
        for(i=0;i<row_size;i++)
            for(j=0;j<col_size;j++)
            {
                if(minefield[i][j] == 'P')
                {
                    count_minefield(minefield, i, j);
                    break;
                }
            }
        printf("%d\n",goldcounter);
        count++;
    }
    return 0;
}

// To read in the minefield
void scan_minefield(char mines[][MAX_COLS+1],
                    int row, int col)
{
	int r;
	getchar();
	for (r=0; r<row; r++){
		gets(mines[r]);
	}
}

//To read where the minecluster is.

void count_minefield(char minefield[][MAX_COLS+1], int row, int col)
{
    int i,j;
    minefield[row][col]='#';
    for(i=row-1;i<=row+1;i++)
        for(j=col-1;j<=col+1;j++)
            if(minefield[i][j]=='.')
                count_minefield(minefield,i,j);
            else if(minefield[i][j]=='G'){
                count_minefield(minefield,i,j);
                goldcounter++;
            }
}
