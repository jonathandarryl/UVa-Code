#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int input,station[1422];
    bool possible;
    while(cin>>input && input){
        possible = true;
        for(int i=0;i<input;i++){
            cin>>station[i];
        }
        station[input] = 1422;
        sort(station,station+input);
        for(int i=0;i<input-1;i++){
            if(station[i+1]-station[i]>200){
                possible = false;
                break;
            }
        }
        if(possible && (1422-station[input-1])*2<=200){
            cout<<"POSSIBLE"<<endl;
        }
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
