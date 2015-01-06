#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int activity, remember,time1,time2,h1,m1,h2,m2;
    int counter = 1;
    int longest,rememberstart, rememberend, rememberstarttemp,longtemp, timeh,timem;
    string dummy;
    int h,m, count;
    bool busy;
    while(cin>>activity){
        int sleep[480];
        for(int i=0;i<480;i++)
            sleep[i] = 0;
        for(int i=0;i<activity;i++){
            scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
            getline(cin,dummy);
            time1 = h1*60 + m1 - 600;
            time2 = h2*60 + m2 - 600;
            for(int i=time1;i<time2;i++)
                sleep[i] = 1;
        }
        count = 0;
        longest = 0;
        rememberstart = 0;
        rememberstarttemp = 0;
        busy = true;
        for(int i=0;i<480;i++){
            if(busy && sleep[i]==0){
                busy = false;
                rememberstarttemp = i;
                count = 1;
            }
            else if(!busy && sleep[i]==1){
                busy = true;
                if(longest<i - rememberstarttemp){
                    longest = i - rememberstarttemp;
                    rememberstart = rememberstarttemp;

                }
                count = 0;
            }
            else
                count++;
        }
        if(!busy){
            if(longest< count){
                longest = count;
                rememberstart = rememberstarttemp;
            }
        }

        cout<<"Day #"<<counter<<": the longest nap starts at ";
        h = longest/60;
        m = longest%60;
        timeh = (rememberstart+600)/60;
        timem = (rememberstart+600)%60;
        cout<<timeh<<":";
        if(timem<10)
            cout<<"0";
        cout<<timem<<" and will last for";
        if(h>0)
            cout<<" "<<h<<" hours and";
        cout<<" "<<m<<" minutes."<<endl;
        counter++;
    }
    return 0;
}
