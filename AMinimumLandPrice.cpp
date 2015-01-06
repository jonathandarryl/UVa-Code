#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main(void){
    long long land[41];
    long long test,j,cost,tempnum;
    cin>>test;
    for(int i=0;i<test;i++){
        for(j=0;j<40;j++){
            cin>>land[j];
            if(!land[j])
                break;
        }
        j--;
        sort(land,land+j+1);

        cost = 0;
        tempnum = j;
        for(int k=0;k<=j;k++){
            cost+= pow(land[tempnum],k+1)*2;
            tempnum--;
        }
        if(cost>5000000)
            cout<<"Too expensive";
        else
            cout<<cost;
        cout<<endl;
    }

}
