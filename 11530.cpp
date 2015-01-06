#include<iostream>
#include<string>

using namespace std;

int main(void){
    int test,counter;
    int value[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string sms;
    cin>>test;
    getline(cin,sms);
    for(int i=1;i<=test;i++){
        counter = 0;
        cout<<"Case #"<<i<<": ";
        getline(cin,sms);
        for(int j=0;j<sms.length();j++){
            if(sms.at(j)==' ')
                counter++;
            else{
                counter+=value[(int)sms.at(j) - 97];
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}
