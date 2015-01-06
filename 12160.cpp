#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int main(void){
    int L, U, R,casenum=0;
    int verify[10000];
    bool arr[10000];
    bool found;
    int adder[10];
    while(cin>>L>>U>>R && (L||U||R)){
        found = false;
        for(int i=0;i<R;i++)
            cin>>adder[i];
        for(int i=0;i<10000;i++){
            verify[i] = 0;
            arr[i] = false;
        }
        queue<int> q;
        q.push(L);
        verify[L] = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x==U){
                found = true;
                printf("Case %d: %d\n",++casenum,verify[U]);
                break;
            }
            for(int i=0;i<R;i++){
                int y = (x+adder[i])%10000;
                if(!arr[y]){
                    arr[y] = true;
                    verify[y]=verify[x]+1;
                    q.push(y);
                }
            }
        }
        if(!found)
            printf("Case %d: Permanently Locked\n",++casenum);
    }


}
