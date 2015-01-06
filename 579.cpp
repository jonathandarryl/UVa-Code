#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    int hour, minute;
    double atHour, atMin, degree;
    string test;
    while(cin>>test){
        if(test == "0:00")
            break;
        if(test.length() == 5){
            hour = ((int) test.at(0) - 48) * 10 + ((int) test.at(1) - 48);
            minute = ((int) test.at(3) - 48) * 10 + ((int) test.at(4) - 48);
        }
        else if(test.length() == 4){
            hour =  (int) test.at(0) - 48;
            minute = ((int) test.at(2) - 48) * 10 + ((int) test.at(3) - 48);
        }
        if (hour == 12)
            hour = 0;
        atMin = minute*6;
        atHour = hour*30 + minute*0.5;
        degree = max(atMin,atHour) - min(atMin,atHour);
        if(degree>180)
            degree =360 - degree;
        printf("%.3f\n",degree);

    }
    return 0;
}
