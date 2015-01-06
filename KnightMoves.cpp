#include<map>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main(void){
    map<int,int> dist;
    string from,to;
    int searched;
    int dr[]={-2,-2,-1,1,2,2,1,-1};//untuk huruf
    int dc[]={-1,1,2,2,1,-1,-2,-2};//untuk angka
    while(cin>>from>>to){
        cout<<"To get from "<<from<<" to "<<to<<" takes";
        if(from==to){
            printf(" 0 knight moves.\n");
        }
        else{
            searched = (to.at(0)-'a')*10 + to.at(1)-'0';
            dist.clear();
            queue<int> nomor;
            queue<int> huruf;
            int x = from.at(1)-'0';
            int y = from.at(0)-'a';
            dist[y*10+x] = 0;
            nomor.push(x);
            huruf.push(y);
            while(!nomor.empty()){
                x = nomor.front();nomor.pop();
                y = huruf.front();huruf.pop();
                for(int i=0;i<8;i++){
                    int xtemp=x+dc[i];
                    int ytemp=y+dr[i];
                    if(xtemp>=1 && xtemp<=8 && ytemp>=0 && ytemp<8){
                        if(!dist[ytemp*10+xtemp]){
                            dist[ytemp*10+xtemp] = dist[y*10+x]+1;
                            nomor.push(xtemp);
                            huruf.push(ytemp);
                        }
                        if(dist[searched])
                            break;
                    }

                }
                if(dist[searched])
                    break;
            }
            printf(" %d knight moves.\n",dist[searched]);
        }
    }
    return 0;
}
