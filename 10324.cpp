#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    string input;
    char now;
    int counter, start,end,query,temp;
    short zero[1000000];
    bool dif;
    counter = 1;
    while(getline(cin,input)){
        if(input.length()==0)
            break;
        printf("Case %d:\n",counter);
        scanf("%d",&query);
        zero[0] = 0;
        now = input.at(0);
        for(int i=1;i<input.length();i++){
            if(input.at(i)==now)
                zero[i] = zero[i-1];
            else{
                now = input.at(i);
                zero[i] = zero[i-1]+1;
            }
        }
        for(int i=0;i<query;i++){
            scanf("%d %d",&start,&end);
            if(zero[start]==zero[end])
                printf("Yes\n");
            else
                printf("No\n");
        }
        counter++;
        getline(cin,input);
    }
    return 0;
}
