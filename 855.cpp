#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int street[50001], avenue[50001];
    int test, str, ave,friends;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>str>>ave>>friends;
        for(int j=0;j<friends;j++)
            cin>>street[j]>>avenue[j];
        sort(street,street+friends);
        sort(avenue,avenue+friends);
        if(friends%2==1){
            str = street[friends/2];
            ave = avenue[friends/2];
        }
        else{
            str = street[friends/2-1];
            ave = avenue[friends/2-1];
        }
        cout<<"(Street: "<<str<<", Avenue: "<<ave<<")"<<endl;

    }
    return 0;
}
