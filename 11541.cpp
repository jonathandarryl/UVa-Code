#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main(void){
    int input,length,val;
    string in;
    char rem;
    scanf("%d",&input);
    for(int i=1;i<=input;i++){
        printf("Case %d: ",i);
        cin>>in;
        length = in.length();
        for(int h=0;h<length;){
            rem = in.at(h);
            val = 0;
            h++;
            while(in.at(h)>='0' && in.at(h)<='9'){
                val*=10;
                val+=(in.at(h))-'0';
                h++;
                if(h==length)
                    break;
            }
            for(int j=0;j<val;j++)
                printf("%c",rem);
        }
        printf("\n");
    }
}
