#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
int main(void){
    map<long long, int> catalan;
    catalan[1] = 1;
    catalan[2] = 2;
    catalan[5] = 3;
    catalan[14] = 4;
    catalan[42] = 5;
    catalan[132] = 6;
    catalan[429] = 7;
    catalan[1430] = 8;
    catalan[4862] = 9;
    catalan[16796] = 10;
    catalan[58786] = 11;
    catalan[208012] = 12;
    catalan[742900] = 13;
    catalan[2674440] = 14;
    catalan[9694845] = 15;
    catalan[35357670] = 16;
    catalan[129644790] = 17;
    catalan[477638700] = 18;
    catalan[1767263190] = 19;
    long long input;
    while(cin>>input)
        cout<<catalan[input]<<endl;
    return 0;
}
