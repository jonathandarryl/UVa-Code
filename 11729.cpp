#include<iostream>
#include<algorithm>
using namespace std;
typedef struct{
    int brief;
    int comm;
}soldier;

bool comp(soldier a, soldier b){
    if(a.comm != b.comm)
        return a.comm<b.comm;
    return a.brief<b.brief;
}
int main(void){
    int test;
    int counter = 1;
    long long totalbrief, totalcomm;
    soldier sol[1001];
    while(cin>>test && test){

        totalbrief = totalcomm = 0;
        for(int i=0;i<test;i++){
            cin>>sol[i].brief>>sol[i].comm;
            totalbrief+=sol[i].brief;
            totalcomm+=sol[i].comm;
        }
        cout<<"Case "<<counter++<<": ";
        sort(sol,sol+test);
        if(totalbrief>=(totalcomm-sol[test-1].brief))
            cout<<totalbrief+sol[test-1].comm;
        else{

        }
        cout<<endl;

    }
    return 0;
}
