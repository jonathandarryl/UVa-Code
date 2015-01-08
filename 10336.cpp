#include<iostream>
#include<string.h>
#include<map>
#include<stdio.h>
using namespace std;
void count(char input[][1000],int x, int y, char language);
int main(void){
    int test;
    int x,y, max;
    cin>>test;
    char input[1000][1000];
    map<char,int> lang;
    for(int i=1;i<=test;i++){
        lang.clear();
        cin>>x>>y;
        getchar(); // to catch the newline
        for (int r=0; r<x; r++)
            gets(input[r]);
        for(int j=0;j<x;j++)
            for(int k=0;k<y;k++){
                if(input[j][k]!='.'){
                    lang[input[j][k]]++;
                    count(input,j,k,input[j][k]);
                }
            }
        cout<<"World #"<<i<<endl;
        while(true){
            max = 0;
            for(map<char,int>::iterator it = lang.begin();it!=lang.end();it++){
                if(it->second>max)
                    max = it->second;
            }
            if(max == 0)
                break;
            for(map<char,int>::iterator it = lang.begin();it!=lang.end();it++){
                if(it->second == max){
                    cout<<it->first<<": "<<it->second<<endl;
                    it->second = 0;
                }
            }
        }
    }
    return 0;
}

void count(char input[][1000], int x, int y, char language){
    input[x][y] = '.';
    if(input[x-1][y]==language)
        count(input,x-1,y,language);
    if(input[x+1][y]==language)
        count(input,x+1,y,language);
    if(input[x][y+1]==language)
        count(input,x,y+1,language);
    if(input[x][y-1]==language)
        count(input,x,y-1,language);
}
