#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(void){
    int player, games, pl1, pl2;
    string move1, move2;
    int win[200];
    int lose[200];
    bool first = true;
    while(cin>>player && player){
        cin>>games;
        if(!first)
            cout<<endl;
        else
            first = false;
        memset(win,0,sizeof win);
        memset(lose,0,sizeof lose);
        games = games*player*(player-1)/2.0;
        for(int i=0;i<games;i++){
            cin>>pl1>>move1>>pl2>>move2;
            if(move1=="scissors" && move2=="rock"){
                lose[pl1]++;
                win[pl2]++;
            }
            else if(move1=="rock" && move2=="scissors"){
                lose[pl2]++;
                win[pl1]++;
            }
            else if(move1=="scissors" && move2=="paper"){
                lose[pl2]++;
                win[pl1]++;
            }
            else if(move1=="paper" && move2=="scissors"){
                lose[pl1]++;
                win[pl2]++;
            }
            else if(move1=="paper" && move2=="rock"){
                lose[pl2]++;
                win[pl1]++;
            }
            else if(move1=="rock" && move2=="paper"){
                lose[pl1]++;
                win[pl2]++;
            }
        }
        for(int i=1;i<=player;i++){
            if(lose[i]==0 && win[i]==0)
                cout<<"-"<<endl;
            else{
                printf("%.3lf\n",(double)win[i]/(win[i]+lose[i]));
            }
        }
    }
    return 0;
}
