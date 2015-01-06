#include<iostream>
using namespace std;

int main(void){
    int test;
    int newcola, total, empty;
    while(cin>>test && test){
        total = 0;
        empty = test;
        while(empty>=3){
            newcola = empty/3;
            empty = empty%3 + newcola;
            total+=newcola;
        }
        if(empty == 2){
            total++;
        }
        cout<<total<<endl;
    }
    return 0;
}
