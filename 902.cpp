#include<map>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    map<string,int> freq;
    int in,max,length,a;
    string str,rem,str2;
    while(scanf("%d",&in)==1){
        getline(cin,str);
        max = 0;
        freq.clear();
        length = str.length() - in + 1;
        for(int i=0;i<=length;i++){
            str2 = str.substr(i,in);
            freq[str2]++;
            if(freq[str2]>=max){
                max = freq[str2];
                rem = str2;
            }
        }
        cout<<rem<<endl;

    }
    return 0;
}
