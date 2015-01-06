#include<iostream>
#include<map>
#include<stdio.h>
#include<queue>
#include<stdlib.h>
using namespace std;

int main(void){
    int from[4],to[4],temp[4];
    int dr[]={1,-1};
    int forbidden,num,value,toz;
    map<int,int>forbid;
    int test,ori;
    scanf("%d",&test);
    while(test--){
        for(int i=0;i<4;i++)
            scanf("%d",&from[i]);
        for(int i=0;i<4;i++)
            scanf("%d",&to[i]);
        scanf("%d",&forbidden);
        forbid.clear();
        for(int i=0;i<forbidden;i++){
            value = 0;
            for(int j=0;j<4;j++){
                scanf("%d",&num);
                value = value*10 + num;
            }
            forbid[value]=1;
        }
        if(from[0]==to[0] && from[1]==to[1] && from[2] == to[2] && from[3] == to[3])
            printf("0\n");
        else{
            map<int,int>dist;
            dist.clear();
            toz = to[0]*1000 + to[1]*100 + to[2]*10 + to[3];
            value = from[0]*1000+from[1]*100+from[2]*10+from[3];
            dist[value] = 1;
            queue<int> n1;n1.push(from[0]);
            queue<int> n2;n2.push(from[1]);
            queue<int> n3;n3.push(from[2]);
            queue<int> n4;n4.push(from[3]);
            while(!n1.empty()){
                from[0] = n1.front();n1.pop();
                from[1] = n2.front();n2.pop();
                from[2] = n3.front();n3.pop();
                from[3] = n4.front();n4.pop();
                ori = from[0]*1000 + from[1]*100 + from[2]*10 + from[3];
                for(int m=0;m<4;m++)
                    temp[m]=from[m];
                for(int i=0;i<4;i++){
                    for(int j=0;j<2;j++){
                        from[i]+=dr[j];
                        if(from[i]>9)
                            from[i]=0;
                        else if(from[i]<0)
                            from[i]=9;
                        value = 0;
                        for(int k=0;k<4;k++){
                            value*=10;
                            value+=from[k];
                        }
                        if(!forbid[value] && !dist[value]){
                                        dist[value]=dist[ori]+1;
                                        n1.push(from[0]);
                                        n2.push(from[1]);
                                        n3.push(from[2]);
                                        n4.push(from[3]);
                                    }
                        from[i]=temp[i];
                    }
                }
                if(dist[toz])
                    break;
            }
            if(dist[toz])
                printf("%d\n",dist[toz]-1);
            else
                printf("-1\n");

        }
    }
    return 0;
}
