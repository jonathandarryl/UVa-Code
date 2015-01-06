#include<iostream>
#include<string>
using namespace std;
int main(void){
    int test, now;
    int top,west,east,bot,north,south,temp;
    string input;

    while(true){
        top = 1;
        bot = 6;
        west = 3;
        east = 4;
        north = 2;
        south = 5;
        cin>>test;
        if(test == 0)
            return 0;

        for(int i=0;i<test;i++){
            cin>>input;
            if(input == "north"){
                temp = top;
                top = south;
                south = bot;
                bot = north;
                north = temp;
            }
            else if(input == "west"){
                temp = top;
                top = east;
                east = bot;
                bot = west;
                west = temp;
            }
            else if(input == "south"){
                temp = top;
                top = north;
                north = bot;
                bot = south;
                south = temp;
            }
            else if(input == "east"){
                temp = top;
                top = west;
                west = bot;
                bot = east;
                east = temp;
            }

        }
    cout<<top<<endl;
    }
    return 0;
}
