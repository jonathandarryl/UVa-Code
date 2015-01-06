#include<map>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int main(void){
    long long test,tobetested;
    long long arr[1001];
    vector<long long> dist;
    int casecounter = 1;
    vector<long long>::iterator it;
    while(cin>>test&&test){
        dist.clear();
        for(int i=0;i<test;i++){
            cin>>arr[i];
            for(int j=0;j<i;j++)
                dist.push_back(arr[i]+arr[j]);
        }
        printf("Case %d:\n",casecounter++);
        cin>>test;
        for(int i=0;i<test;i++){
            cin>>tobetested;
            printf("Closest sum to %lld is ",tobetested);
            if(!dist[tobetested]){
                long long temp,temp2;
                it = lower_bound(dist.begin(),dist.end(),tobetested);
                temp = abs(*it - tobetested);
                temp2 = *it;
                it--;
                if(temp>abs(*it - tobetested)){
                    cout<<*it<<".\n";
                }
                else
                    cout<<temp2<<".\n";
            }
            else{
                cout<<tobetested<<".\n";
            }
        }
    }
    return 0;
}
