#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int N,Q,input,casecounter = 1;
    vector<int> marble;
    while(scanf("%d %d",&N,&Q) && N && Q){
        marble.clear();
        for(int i=1;i<=N;i++){
            scanf("%d",&input);
            marble.push_back(input);
        }
        sort(marble.begin(),marble.end());
        printf("CASE# %d:\n",casecounter++);
        for(int i=0;i<Q;i++){
            scanf("%d",&input);
            if(binary_search(marble.begin(),marble.end(),input)){
                printf("%d found at ",input);
                cout<<int(lower_bound(marble.begin(),marble.end(),input)-marble.begin())+1<<endl;
            }
            else
                printf("%d not found\n",input);
        }

    }
    return 0;
}
