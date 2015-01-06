#include<iostream>
using namespace std;

int main(void){
    int h1,m1,h2,m2, timefrom, timeto;
    while(cin>>h1>>m1>>h2>>m2){
        if(h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0)
            return 0;
        timefrom = h1*60 + m1;
        timeto = h2*60 + m2;
        if(timefrom<=timeto)
            cout<<timeto-timefrom;
        else
            cout<<1440 - timefrom + timeto;
        cout<<endl;

    }


    return 0;
}
