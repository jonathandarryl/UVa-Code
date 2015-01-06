#include<iostream>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;

char dimension[101][101];
int counter;
int maxcol,maxrow;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};

int floodfill(int row, int col, char c1, char c2){
    //cout<<row<<col<<dimension[row][col];
    if(row<0||col<0||row>=maxrow||col>=maxcol)  return 0;
    if(dimension[row][col]!=c1)
        return 0;
    dimension[row][col] = c2;
    int ans = 1;
    for(int i=0;i<8;i++)
        ans+=floodfill(row+dr[i],col+dc[i],c1,c2);
    return ans;
}

int main(void){

    int test,row,col;
    scanf("%d",&test);
    string in;
    getline(cin,in);
    getline(cin,in);
    while(test--){
        counter = 0;
        while(true){
            getline(cin,in);
            if(in.at(0)!='W' && in.at(0)!='L'){
                stringstream(in)>>row>>col;
                break;
            }
            for(int i=0;i<in.length();i++)
                dimension[counter][i]=in.at(i);
            counter++;
            maxcol = in.length();
        }

        maxrow = counter;
        cout<<floodfill(row-1,col-1,'W','.')<<endl;

        while(getline(cin,in)){
            if(in.empty())
                break;
            stringstream(in)>>row>>col;
            if(dimension[row-1][col-1]=='.')
                cout<<floodfill(row-1,col-1,',','W')<<endl;
            else
                cout<<floodfill(row-1,col-1,'W','.')<<endl;
        }
        if(test)
            cout<<endl;
    }
    return 0;
}
