#include<iostream>
#include<sstream>
#include<stdio.h>
using namespace std;

int main(void){

    string str;
    int h,m,s,speed, timenow;
    double total;
    scanf("%d:%d:%d",&h,&m,&s);
    timenow = h*3600 + m*60 + s;
    total = 0;
    cin>>speed;
    while(scanf("%d:%d:%d",&h,&m,&s)==3){
        getline(cin,str);
        total+= (h*3600+m*60+s-timenow)*speed/3600.0;
        timenow=h*3600+m*60+s;
        if(str.length()>2)
            stringstream(str)>>speed;
        else{
            printf("%02d:%02d:%02d %.2lf km\n",h,m,s,total);
        }

    }

}
