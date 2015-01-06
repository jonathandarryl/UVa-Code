#include<string>
#include<iostream>

using namespace std;

int main(void){
    string base;
    while(cin>>base){
        if(base.length()>1 || base.length() == 0)
            cout<<"such number is impossible!"<<endl;
        else if((int)base.at(0)<58 && (int) base.at(0)>47)
            cout<<(int) base.at(0) - 47<<endl;
        else if((int)base.at(0)<91 && (int)base.at(0)>64)
            cout<<(int) base.at(0) - 54<<endl;
        else if((int) base.at(0)<123 && (int)base.at(0)>96)
            cout<<(int)base.at(0) - 60<<endl;
        else
            cout<<"such number is impossible!"<<endl;
    }
    return 0;
}
