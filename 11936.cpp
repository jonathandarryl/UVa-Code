#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
    int test;
    int length[3];
    cin>>test;
    for(int i=0;i<test;i++){
        for(int j=0;j<3;j++)
            cin>>length[j];
        sort(length,length+3);
        if(length[0]+length[1]>length[2])
            cout<<"OK";
        else
            cout<<"Wrong!!";
        cout<<endl;
    }
    return 0;
}
