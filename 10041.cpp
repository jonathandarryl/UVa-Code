#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(){
    int testcase, numrel, median, totaldist;
    int dist[500];
    cin>>testcase;

    for(int i=0;i<testcase;i++){
        cin>>numrel;

        totaldist = 0;
        for(int j=0;j<numrel;j++){
            cin>>dist[j];

        }
        sort(dist,dist+numrel);
        if(numrel%2==1)
            median = dist[numrel/2];
        else
            median = (dist[numrel/2-1]+dist[numrel/2])/2;
        for(int j=0;j<numrel;j++){
            totaldist+=abs(dist[j]-median);
        }
        cout<<totaldist<<endl;
    }
    return 0;
}
