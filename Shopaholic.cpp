#include<algorithm>
#include<iostream>
using namespace std;

int main(void){
    int goods[20000];
    int test, numgood,disc;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>numgood;
        disc = 0;
        for(int j=0;j<numgood;j++)
            cin>>goods[j];
        sort(goods,goods+numgood);
        for(int j=numgood-3;j>=0;j-=3)
            disc+=goods[j];
        cout<<disc<<endl;
    }
    return 0;
}
