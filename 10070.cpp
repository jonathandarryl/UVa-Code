#include<iostream>

using namespace std;

int main(void){
    long long int year;
    bool isLeap, isHuluculu, isBulukulu;
    while(cin>>year){
        isLeap = isHuluculu = isBulukulu = false;
        if(year%400 == 0 || (year%4==0 && year%100!=0)){
            isLeap = true;
            cout<<"This is leap year."<<endl;
        }
        if(year%15==0){
            isHuluculu = true;
            cout<<"This is huluculu festival year."<<endl;
        }
        if(isLeap && year%55 == 0){
            isBulukulu = true;
            cout<<"This is bulukulu festival year."<<endl;
        }
        if(!isLeap && !isHuluculu && !isBulukulu)
            cout<<"This is an ordinary year."<<endl;
        cout<<endl;
    }

    return 0;
}
