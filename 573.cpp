#include<iostream>

using namespace std;

int main(void){
    double height, up, down, fatigue, decrease, distance;
    int day;
    while(cin>>height>>up>>down>>fatigue && height){
        decrease = fatigue/100*up;
        distance = 0;
        day = 1;
        while(day==1 || distance>0 && distance<=height){
            distance+=up;
            up-=decrease;
            if(up<=0)
                up = 0;
            if(distance>height)
                break;
            distance-=down;
            if(distance<0)
                break;
            day++;
        }
        if(distance>=height)
            cout<<"success on day "<<day<<endl;
        else
            cout<<"failure on day "<<day<<endl;

    }

}
