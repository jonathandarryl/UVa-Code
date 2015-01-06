#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;
int row, col;
char maze[10][10];
bool visited[10][10];
int dc[] = {-1,0,1};
int dr[] = {0,-1,0};
int loc[7];
string in = "IEHOVA#";

void floodfill(int crow, int ccol, vector<int> r, vector<int> c, int current){
    if(crow<0||ccol<0||crow>=row||ccol>=col||visited[crow][ccol])
        return;
    if(current==in.length()-1 && maze[crow][ccol]=='#'){
        int rownow,colnow;
        rownow = r.at(0);
        colnow = c.at(0);

        for(int i=1;i<c.size()-1;i++){
            if(rownow>r.at(i))
                cout<<"forth ";
            else if(colnow<c.at(i))
                cout<<"right ";
            else if(colnow>c.at(i))
                cout<<"left ";
            colnow = c.at(i);
            rownow = r.at(i);
        }
        if(rownow>r.at(c.size()-1))
                cout<<"forth"<<endl;
            else if(colnow<c.at(c.size()-1))
                cout<<"right"<<endl;
            else if(colnow>c.at(c.size()-1))
                cout<<"left"<<endl;
        return;
    }


    if(in.at(current)!=maze[crow][ccol])
        return;
    //cout<<"IN: at"<<in.at(current)<<"  I "<<crow<<" J "<<ccol<<endl;
    visited[crow][ccol]=true;
    for(int d=0;d<3;d++){
        r.push_back(crow+dr[d]);
        c.push_back(ccol+dc[d]);
        floodfill(crow+dr[d],ccol+dc[d],r,c,current+1);
        r.pop_back();
        c.pop_back();
    }
}

int main(void){
    int test;
    cin>>test;
    vector<int> r;
    vector<int> c;
    while(test--){
        cin>>row>>col;
        getchar();
        r.clear();
        c.clear();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                visited[i][j]=false;
            }
        for(int i=0;i<row;i++)
            gets(maze[i]);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(maze[i][j]=='@'){
                    visited[i][j]=true;
                    r.push_back(i);
                    c.push_back(j);
                    //cout<<"I "<<i<<" J "<<j<<endl;
                    for(int d=0;d<3;d++){
                        r.push_back(i+dr[d]);
                        c.push_back(j+dc[d]);
                        floodfill(i+dr[d],j+dc[d],r,c,0);
                        r.pop_back();
                        c.pop_back();
                    }
                }

    }
    return 0;
}
