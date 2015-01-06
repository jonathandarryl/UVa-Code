#include <stdio.h>
#include <string.h>
#define MINE '*'   // a mine-filled cell
#define FREE '.'   // a mine-free cell
#define MAX_ROWS 120  // maximum rows of a minefield
#define MAX_COLS 120  // maximum columns of a minefield
#include<iostream>
using namespace std;
void scan_minefield(char [][MAX_COLS+1], int, int);
void count_minefield(char [][MAX_COLS+1], int, int);
int counting;
int main(void)
{
	char minefield[MAX_ROWS][MAX_COLS+1];
	int row_size, col_size; // actual size of minefield read
    int counter,i,j;
    bool found;
    while(cin>>row_size>>col_size && row_size && col_size){
        scan_minefield(minefield,row_size,col_size);
        counter=0;
        for(i=0;i<row_size;i++)
            for(j=0;j<col_size;j++)
            {
                if(minefield[i][j] == MINE)
                {
                    counting = 0;
                    count_minefield(minefield,i,j);
                    if(counting == 1)
                        counter++;
                }
            }
        printf("%d\n",counter);
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
    counting++;
    minefield[row][col]=FREE;
    for(i=row-1;i<=row+1;i++)
        for(j=col-1;j<=col+1;j++)
            if(minefield[i][j]==MINE)
                count_minefield(minefield,i,j);
}
