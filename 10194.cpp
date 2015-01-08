#include<iostream>
#include<string.h>
using namespace std;
typedef struct{
    string name;
    int point;
    int game_played;
    int win;
    int tie;
    int loss;
    int goaldif;
    int goalscored;
    int goalagainst;
}team;
int main(void){
    int test;
    int numteam, nummatch;
    string event;
    team teams[1000];
    cin>>test;
    getline(cin,event);
    for(int i=0;i<test;i++){
        getline(cin,event);
        cout<<event<<endl;
        cin>>numteam;
        for(int j=0;j<numteam;j++){
            getline(cin,teams[j].name);
        }
        cin>>nummatch;
        for(int j=0;j<nummatch;j++){

        }


    }
    return 0;
}
