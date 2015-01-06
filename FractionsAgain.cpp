#include<iostream>
using namespace std;

int gcd(int,int);

int main(void){
    int test;
    int x, res, counter;
    while(cin>>test){
        x = test*2;
        counter = 0;
        for(int i=test+1;i<=x;i++){
            res = i-test;
            if(gcd(res,test*i)==res)
                counter++;
        }
        cout<<counter<<endl;
        for(int i=test+1;i<=x;i++){
            res = i-test;
            if(gcd(res,test*i)==res){
                cout<<"1/"<<test<<" = 1/"<<test*i/res<<" + 1/"<<i<<endl;
            }
        }

    }

    return 0;
}

int gcd(int a , int b){return (b==0?a:gcd(b,a%b));}
