#include <stdio.h>
#include <string.h>
#define MAX_ROWS 101  // maximum rows of a minefield
#define MAX_COLS 100  // maximum columns of a minefield
#include<iostream>
using namespace std;
void scan_minefield(int, int);
int count_minefield(int, int, int, int, char, char);
int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char savechar;
char minefield[MAX_ROWS][MAX_COLS+1];
int main(void)
{
    int maxtemp, maxcont,dummy;
	int row_size, col_size; // actual size of minefield read
    int i,j, firstminex, firstminey;
    while(scanf("%d %d", &row_size, &col_size) == 2){
        scan_minefield(row_size,col_size);
        cin>>firstminex>>firstminey;
        savechar = minefield[firstminex][firstminey];
        dummy=count_minefield(firstminex,firstminey, row_size, col_size, savechar, savechar+1);
        maxcont = dummy;
        for(i=0;i<row_size;i++)
            for(j=0;j<col_size;j++)
            {
                if(minefield[i][j] == savechar)
                {
                    maxtemp = count_minefield(i, j, row_size,col_size, savechar, savechar+1);
                    if(maxtemp>maxcont)
                        maxcont = maxtemp;
                }
            }
        printf("%d\n",maxcont);
    }
    return 0;
}

// To read in the minefield
void scan_minefield(int row, int col)
{
	int r;
	getchar();
	for (r=0; r<row; r++){
		gets(minefield[r]);
	}
}

//To read where the minecluster is.

int count_minefield(int row, int col, int row_size, int col_size, char c1, char c2)
{
    if(row<0 || row>=row_size || col<0 || col>=col_size)    return 0;
    if(minefield[row][col]!=c1) return 0;
    int ans = 1;
    minefield[row][col] = c2;
    if(col==0)
        ans+=count_minefield(row,col_size-1,row_size,col_size,c1,c2);
    if(col==col_size-1)
        ans+=count_minefield(row,0,row_size,col_size,c1,c2);
    for(int i=0;i<8;i++)
        ans+=count_minefield(row+dr[i],col+dc[i], row_size, col_size, c1, c2);
    return ans;
}

