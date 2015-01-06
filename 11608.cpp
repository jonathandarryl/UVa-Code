#include<iostream>
using namespace std;

int main(void){
    long long available, madenew[12], needed[12], counter = 1;
    while(cin>>available && available>-1){
        for(int i=0;i<12;i++)
            cin>>madenew[i];
        for(int i=0;i<12;i++)
            cin>>needed[i];
        cout<<"Case "<<counter<<":"<<endl;
        for(int i=0;i<12;i++){
            if(available>=needed[i]){
                cout<<"No problem! :D"<<endl;
                available-=needed[i];
            }
            else
                cout<<"No problem. :("<<endl;
            available+=madenew[i];
        }
        counter++;
        available = 0;
    }

    return 0;
}
