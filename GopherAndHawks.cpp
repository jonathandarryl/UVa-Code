#include<iostream>
#include<stdio.h>
#include<sstream>
#include<queue>
#include<map>
using namespace std;

typedef struct{
    double x;
    double y;
}Point;

int main(void){
    int v,m,counter,maxi;
    Point pt[1001];
    string input;
    while(cin>>v>>m && v && m){
        counter = 0;
        maxi = v*m*v*m;
        while(getline(cin,input)){
            if(input.empty())
                break;
            else{
                stringstream(input)>>pt[counter].x>>pt[counter].y;
                counter++;
            }
        }

    }

    return 0;
}
