#include<iostream>
#include<stdlib.h>
using namespace std;
int main(void){
    int x1,y1,x2,y2, move;
    while(cin>>x1>>y1>>x2>>y2){
        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            return 0;
        if(x1==x2 && y1 == y2)
            move = 0;
        else if(x1==x2 || y1==y2)
            move = 1;
        else if(abs(x1-x2) == abs(y1-y2))
            move = 1;
        else
            move = 2;
        cout<<move<<endl;
    }
    return 0;

}
