#include <iostream>
#include <string.h>
#include<stdio.h>

void count_eagle(string [], int, int);
int main(void)
{
	string field[27];
	int size; 
    int counter;

    cin>>size;
	for(int i=1;i<=size;i++){
		cin>>field[i];
	}
    for(int i=1;i<size;i++)
        for(int j=0;j<size;j++)
        {
            if(field[i].charAt(j) == '1')
            {
                count_eagle(field, i, j);
                counter++;
            }
        }
    printf("%d",counter);
	return 0;
}





void count_eagle(string[] field, int row, int col){
    
	minefield[row][col]=0;
    for(int i=row-1;i<=row+1;i++)
        for(int j=col-1;j<=col+1;j++)
            if(field[i].charAt(j)=='1')
                count_minefield(minefield,i,j);
}
