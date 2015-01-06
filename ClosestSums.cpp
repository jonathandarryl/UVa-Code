#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main(void){
    long long test[1001];
    int input, query;
    long long data, ans, permanent = 0;
    long long closest;
    int counter = 1;
    bool found, small;
    while(scanf("%d",&input) && input){
        for(int i=0;i<input;i++)
            scanf("%lld",&test[i]);
        sort(test,test+input);
        scanf("%d",&query);
        printf("Case %d:\n",counter++);
        for(int i=0;i<query;i++){
            found = false;
            cin>>data;
            closest = 2147483647;
            if(data>=(test[input-1] + test[input-2]))
                permanent = test[input-1] + test[input-2];
            else{
                for(int j=0;j<input-1;j++){
                    if(test[j]+test[j]>data){
                        if((test[j]+test[j+1] - data) < closest){
                            permanent = test[j] + test[j+1];
                            break;
                        }
                    }
                    for(int k=j+1;k<input;k++){
                        ans = test[j] + test[k];
                        if(ans==data){
                            permanent = ans;
                            found = true;
                            break;
                        }
                        else if(abs(ans-data)<closest){
                            closest = abs(ans-data);
                            permanent = ans;
                        }
                        if(ans>data)
                            break;
                    }
                    if(found)
                        break;
                }
            }

            cout<<"Closest sum to "<<data<<" is "<<permanent<<"."<<endl;
        }
    }
    return 0;
}
