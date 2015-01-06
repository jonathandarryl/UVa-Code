#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
char mines[500][500];
int dr[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};
int maxrow, maxcol;
typedef struct{
    char name;
    int number;
}holes;

void scan_minefield(int row, int col){
	int r;
	getchar();
	for (r=0; r<row; r++){
		gets(mines[r]);
	}
}

bool sortcomp(holes a, holes b){
    if(a.number!=b.number)
        return a.number>b.number;
    else
        return a.name<b.name;
}

int floodfill(int row, int col, char c1, char c2){
    if(row<0||row>=maxrow||col<0||col>=maxcol)  return 0;
    if(mines[row][col]!=c1) return 0;
    mines[row][col] = c2;
    int ans = 1;
    for(int d=0;d<4;d++)
        ans+=floodfill(row+dr[d],col+dc[d],c1,c2);
    return ans;
}
int main(void){
    int counter, countprob = 1;
    holes hole[250000];
    while(cin>>maxrow>>maxcol && maxrow && maxcol){
        scan_minefield(maxrow,maxcol);
        counter = 0;
        for(int i=0;i<maxrow;i++)
            for(int j=0;j<maxcol;j++)
                if(mines[i][j]!='.'){
                    hole[counter].name = mines[i][j];
                    hole[counter].number = floodfill(i,j,mines[i][j],'.');
                    counter++;
                }

        cout<<"Problem "<<countprob++<<":"<<endl;
        if(counter>1)   sort(hole,hole+counter,sortcomp);
        if(counter==0)  cout<<endl;
        else
            for(int i=0;i<counter;i++)
                cout<<hole[i].name<<" "<<hole[i].number<<endl;

    }

}
