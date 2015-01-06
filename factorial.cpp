#include<iostream>
using namespace std;

int main(void){
    long long int n;
    while(cin>>n){
        if(n<0){
            if((-n)%2==0)
                cout<<"Underflow!"<<endl;
            else
                cout<<"Overflow!"<<endl;
        }
        else{
            if(n<8)
                cout<<"Underflow!"<<endl;
            else if(n>13)
                cout<<"Overflow!"<<endl;
            else{
                switch(n){
                    case 8: cout<<"40320"<<endl;
                        break;
                    case 9: cout<<"362880"<<endl;
                        break;
                    case 10: cout<<"3628800"<<endl;
                        break;
                    case 11: cout<<"39916800"<<endl;
                        break;
                    case 12: cout<<"479001600"<<endl;
                        break;
                    case 13: cout<<"6227020800"<<endl;
                        break;
                }
            }
        }



    }
    return 0;
}
