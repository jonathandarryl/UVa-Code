#include<iostream>
#include<string>
using namespace std;
double conv(string);

int main(void){
    int test,testtime;
    double gmt;
    string time, fr, to, mornaft;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>time;

    }
    return 0;
}

double conv(string time){
    if(time == "UTC" || time == "GMT" || time =="WET")
        return 0;
    if(time == "BST" || time == "IST" || time == "WEST" || time =="CET")
        return 1;
    if(time == "CEST" || time == "EET")
        return 2;
    if(time == "EEST" || time == "MSK")
        return 3;
    if(time == "MSD")
        return 4;
    if(time == "AST" || time == "EDT")
        return -4;
    if(time == "ADT")
        return -3;
    if(time == "NST")
        return -3.5;
    if(time == "NDT")
        return -2.5;
    if(time == "EST" || time == "CDT")
        return -5;
    if(time == "CST" || time == "MDT")
        return -6;
    if(time == "MST" || time == "PDT")
        return -7;
    if(time == "PST" || time == "AKDT")
        return -8;
    if(time == "HST")
        return -10;
    if(time == "AKST")
        return -9;
    if(time == "AEST")
        return 10;
    if(time == "AEDT")
        return 11;
    if(time == "ACST")
        return 9.5;
    if(time == "ACDT")
        return 10.5;
}
