#include<iostream>
#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;

int main(void){
    int test,numphone,length,value,counter;
    map<int,int> dir;
    map<char,int> ph;
    ph['A'] = ph['B'] = ph['C'] = 2;
    ph['D'] = ph['E'] = ph['F'] = 3;
    ph['G'] = ph['H'] = ph['I'] = 4;
    ph['J'] = ph['K'] = ph['L'] = 5;
    ph['M'] = ph['N'] = ph['O'] = 6;
    ph['P'] = ph['R'] = ph['S'] = 7;
    ph['T'] = ph['U'] = ph['V'] = 8;
    ph['W'] = ph['X'] = ph['Y'] = 9;
    char phone[500];
    scanf("%d",&test);
    while(test--){
        scanf("%d",&numphone);
        getchar();
        dir.clear();
        while(numphone--){
            gets(phone);
            length = strlen(phone);
            value = counter = 0;
            for(int i=0;i<length;i++){
                if(phone[i]>='0' && phone[i]<='9'){
                    value*=10;
                    value+=phone[i]-'0';
                    counter++;
                    if(counter==7)
                        break;
                }
                else if(phone[i]>='A' && phone[i]<='Z'){
                    value*=10;
                    value+=ph[phone[i]];
                    counter++;
                    if(counter==7)
                        break;
                }
            }
            dir[value]++;

        }
        bool printed = false;
            for(map<int,int>::iterator it = dir.begin();it!=dir.end();it++)
                if(it->second>1){
                    printf("%03d-%04d %d\n",it->first/10000,it->first%10000,it->second);
                    printed=true;
                }
            if(!printed)
                printf("No duplicates.\n");
        if(test)
            printf("\n");

    }
    return 0;
}
