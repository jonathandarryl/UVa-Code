#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INF 10000000
using namespace std;

int main(void){
    int test, in, casecounter = 1;
    double graph[101][101];
    double x[101],y[101];
    cin>>in;
    while(in--){
        cin>>test;
        for(int i=0;i<test;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<test;i++)
            for(int j=0;j<test;j++){
                graph[i][j] = INF;
                if(i==j)
                    graph[i][j] = 0;
            }
        for(int i=0;i<test-1;i++)
            for(int j=i+1;j<test;j++){
                graph[i][j] = pow(abs(x[i]-x[j]),2) + pow(abs(y[i]-y[j]),2);
                if(graph[i][j]>100)
                    graph[i][j] = INF;
                else
                    graph[i][j] = sqrt(graph[i][j]);
               graph[j][i] = graph[i][j];
            }
        cout<<"Case #"<<casecounter++<<":"<<endl;
        for(int k=0;k<test;k++)
            for(int i=0;i<test;i++)
                for(int j=0;j<test;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        double res = 0;
        for(int i=0;i<test;i++)
            for(int j=0;j<test;j++)
            if(i!=j)
                res = max(res,graph[i][j]);
        if(res==INF)
            cout<<"Send Kurdy"<<endl<<endl;
        else{
            printf("%.4lf\n\n",res);
        }
    }
    return 0;
}
