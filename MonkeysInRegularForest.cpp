#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char tree[1000][1000];
int fills[1000][1000];
int counter,countrow;
int c;
int maxeachrow[1000];
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};

void floodfill(int row, int col, char c1, char c2, int c){
    if(row<0||row>=countrow||col<0||col>=counter)  return;
    if(tree[row][col]!=c1)  return;
    fills[row][col] = c;
    tree[row][col] = c2;
    for(int d=0;d<8;d++)
        floodfill(row+dr[d],col+dc[d],c1,c2,c);
}

int main(void){
    string input;
    while(getline(cin,input)){
        counter = 0;
        for(int i=0;i<input.length();i++)
            if(input.at(i)!=' ')
                tree[0][counter++] = input.at(i);
        countrow = 1;
        c = 1;
        while(getline(cin,input)){
            if(input.at(0)=='%')
                break;
            counter = 0;
            for(int i=0;i<input.length();i++)
                if(input.at(i)!=' ')
                    tree[countrow][counter++] = input.at(i);
            countrow++;
        }
        for(int i=0;i<countrow;i++)
            for(int j=0;j<counter;j++){
                if(tree[i][j]!=' '){
                    floodfill(i,j,tree[i][j],' ',c);
                    c++;
                }
            }
        memset(maxeachrow,0,sizeof maxeachrow);
        for(int i=0;i<counter;i++)
            for(int j=0;j<countrow;j++)
                if(maxeachrow[i]<fills[j][i])
                    maxeachrow[i]=fills[j][i];
        for(int i=0;i<countrow;i++){
            for(int j=0;j<counter-1;j++){
                if(maxeachrow[j]<10)  printf("%d ",fills[i][j]);
                else if(maxeachrow[j]<100)  printf("%2d ",fills[i][j]);
                else if(maxeachrow[j]<1000)  printf("%3d ",fills[i][j]);
                else if(maxeachrow[j]<10000)  printf("%4d ",fills[i][j]);
                else if(maxeachrow[j]<100000)  printf("%5d ",fills[i][j]);
                else if(maxeachrow[j]<1000000)  printf("%6d ",fills[i][j]);
            }
            if(maxeachrow[counter-1]<10)  printf("%d",fills[i][counter-1]);
            else if(maxeachrow[counter-1]<100)  printf("%2d",fills[i][counter-1]);
            else if(maxeachrow[counter-1]<1000)  printf("%3d",fills[i][counter-1]);
            else if(maxeachrow[counter-1]<10000)  printf("%4d",fills[i][counter-1]);
            else if(maxeachrow[counter-1]<100000)  printf("%5d",fills[i][counter-1]);
            else if(maxeachrow[counter-1]<1000000)  printf("%6d",fills[i][counter-1]);
            cout<<endl;
        }
        cout<<"%"<<endl;
    }

}
