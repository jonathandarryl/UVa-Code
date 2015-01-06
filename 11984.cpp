#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int testcase, initial, increase;
    double increasec, total;
    cin>>testcase;

    for(int i=1;i<=testcase;i++){
        cout<<"Case "<<i<<": ";
        cin>>initial>>increase;
        increasec = (5/9.0)*(increase);
        total = initial+increasec;
        printf("%.2lf\n",total);
    }
    return 0;
}
