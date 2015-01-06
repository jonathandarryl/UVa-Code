/* 8 Queens Chess Problem */
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int row[9], TC, a, b, lineCounter; // it is ok to use global variables in competitive programming
int count;
int rowcol[92][9];
int jewel[9][9];
bool place(int col, int tryrow) {
  for (int prev = 1; prev < col; prev++) // check previously placed queens
    if (row[prev] == tryrow || (abs(row[prev] - tryrow) == abs(prev - col)))
      return false; // an infeasible solution if share same row or same diagonal
  return true;
}

void backtrack(int col) {
  for (int tryrow = 1; tryrow <= 8; tryrow++) // try all possible row
    if (place(col, tryrow)) { // if can place a queen at this col and row...
      row[col] = tryrow; // put this queen in this col and row
      if (col == 8) { // a candidate solution & (a, b) has 1 queen
        for(int i=1;i<=8;i++)
            rowcol[count][i]=row[i];
        count++;
      }
      else
        backtrack(col + 1); // recursively try next column
}   }

int main() {
  scanf("%d", &TC);
  int max,temp;
    count = 0;
    memset(row, 0, sizeof row); lineCounter = 0;
    backtrack(1); // generate all possible 8! candidate solutions
  while (TC--) {
      max = 0;

    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            scanf("%d",&jewel[i][j]);
    for(int i=0;i<92;i++){
        temp = 0;
        for(int j=1;j<=8;j++)
            temp+=jewel[j][rowcol[i][j]];
        if(temp>max)
            max = temp;
    }
    printf("%5d\n",max);
  }
  return 0;
}
