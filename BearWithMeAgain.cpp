#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define INF 100000000

using namespace std;

double AdjMat[205][205];

int main(void){
    int K,M,temp1,temp2,temp3;
    double x[205],y[205],r[205];
    while(cin>>K>>M){
        for(int i=0;i<202;i++)
            for(int j=0;j<202;j++){
                if(i!=j)
                    AdjMat[i][j] = INF;
                else
                    AdjMat[i][j] = 0;
            }
        int x[202],y[202],r[202],in;
        cin>>x[0]>>y[0]>>r[0]>>temp1>>temp2>>temp3;
        cin>>in;
        x[in+1] = temp1;
        y[in+1]=temp2;
        r[in+1] = temp3;
        for(int j=1;j<=in;j++)
            cin>>x[j]>>y[j]>>r[j];
        for(int i=0;i<=in;i++)
            for(int j=i+1;j<=in+1;j++){
                AdjMat[i][j] = sqrt(pow(abs(x[i]-x[j]),2) + pow(abs(y[i]-y[j]),2)) - r[i]-r[j];
                if(AdjMat[i][j]<=K*M)
                    AdjMat[j][i] = AdjMat[i][j];
                else{
                    AdjMat[i][j] = AdjMat[j][i] = INF;
                }
            }
        for(int k=0;k<=in+1;k++)
            for(int i=0;i<=in+1;i++)
                for(int j=0;j<=in+1;j++)
                    AdjMat[i][j] = min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
        if(AdjMat[0][in+1]==INF)
            cout<<"Larry and Ryan will be eaten to death."<<endl;
        else
            cout<<"Larry and Ryan will escape!"<<endl;
    }
    return 0;
}
