#include<stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int main(void){
    int test;
    int brand;
    int min,max,count;
    int absmin,absmax,query,number;
    string name,remname;
    map<string,int> low;
    map<string,int> high;
    map<string,int>::iterator it,it1;
    it = low.begin();
    it1 = high.begin();
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&brand);
        absmin = 1000000;
        absmax = 0;
        for(int j=0;j<brand;j++){
            cin>>name;
            scanf("%d %d",&min,&max);
            if(min<absmin)
                absmin = min;
            if(max>absmax)
                absmax = max;
            low[name] = min;
            high[name] = max;
        }
        scanf("%d",&query);
        for(int j=0;j<query;j++){
            scanf("%d",&number);
            if(number<absmin || number>absmax){
                printf("UNDETERMINED\n");
            }
            else{
                count = 0;
                it1 = high.begin();
                for(it=low.begin();it!=low.end();it++,it1++){
                    if(it->second<=number && it1->second>=number){
                        count++;
                        remname = it->first;
                    }

                    if(count>1)
                        break;
                }
                if(count>1)
                    printf("UNDETERMINED\n");
                else
                    cout<<remname<<endl;
            }
        }
        low.clear();
        high.clear();

            printf("\n");
    }

    return 0;
}
