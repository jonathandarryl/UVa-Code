#include <stdio.h>
#include <string.h>
#define MINE 'x'   // a mine-filled cell
#define FREE '.'   // a mine-free cell
#define MAX_ROWS 1000  // maximum rows of a minefield
#define MAX_COLS 1000  // maximum columns of a minefield
#include<iostream>
using namespace std;
void scan_minefield(char [][MAX_COLS+1], int *, int *);
void count_minefield(char [][MAX_COLS+1], int, int);
int main(void)
{
	char minefield[MAX_ROWS][MAX_COLS+1];
	int row_size, col_size; // actual size of minefield read
    int counter,i,j;
    int test;
    cin>>test;
    for(int z=1;z<=test;z++){
        scan_minefield(minefield,&row_size,&col_size);
        counter=0;
        for(i=0;i<row_size;i++)
            for(j=0;j<row_size;j++)
            {
                if(minefield[i][j] == MINE)
                {
                    count_minefield(minefield, i, j);
                    counter++;
                }
            }
        printf("Case %d: %d\n",z,counter);
    }
    return 0;
}

// To read in the minefield
void scan_minefield(char mines[][MAX_COLS+1],
                    int *row_size_p, int *col_size_p)
{
	int r;

	scanf("%d",row_size_p);
	getchar(); // to catch the newline
	for (r=0; r<*row_size_p; r++)
		gets(mines[r]);
}

//To read where the minecluster is.

void count_minefield(char minefield[][MAX_COLS+1], int row, int col)
{
    int i,j;
    minefield[row][col]=FREE;
    if(minefield[row-1][col]==MINE || minefield[row-1][col]=='@')
        count_minefield(minefield,row-1,col);
    if(minefield[row+1][col]==MINE || minefield[row+1][col]=='@')
            count_minefield(minefield,row+1,col);
    if(minefield[row][col-1]==MINE || minefield[row][col-1]=='@')
        count_minefield(minefield,row,col-1);
    if(minefield[row][col+1]==MINE || minefield[row][col+1]=='@')
            count_minefield(minefield,row,col+1);
}
