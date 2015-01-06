#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

int main(void){
    int N,Q,input;
    int arr[51000];
    scanf("%d",&N);
    map<int,int> in;
    map<int,int>::iterator it;
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        in[arr[i]]=1;
    }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        scanf("%d",&input);
        if(input==arr[0]){
            it = in.begin();
            it++;
            printf("X %d\n",it->first);
        }
        else if(input<arr[0])
            printf("X %d\n",arr[0]);
        else if(input==arr[N-1]){
            it = in.end();
            it--;
            it--;
            printf("%d X\n",it->first);
        }
        else if(input>arr[N-1])
            printf("%d X\n",arr[N-1]);
        else{
            it = in.lower_bound(input);
            while(it->first>=input)
                it--;
            printf("%d %d\n",it->first,in.upper_bound(input)->first);
        }
    }
    return 0;
}
