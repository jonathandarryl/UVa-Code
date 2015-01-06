#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int num, remember, temp, testcase;
    int rem[1000];

    cin>>testcase;
    for(int i=1;i<=testcase;i++){
        cin>>num;
        temp = 0;
        memset(rem,0,sizeof rem);
        cout<<"Case #"<<i<<": "<<num<<" is ";
        while(true){
            while(num>0){
                temp+=(num%10)*(num%10);
                num/=10;
            }
            num = temp;
            temp = 0;
            rem[num]++;
            if(num==1){
                cout<<"a Happy number."<<endl;
                break;
            }
            if(rem[num]>1){
                cout<<"an Unhappy number."<<endl;
                break;
            }
        }
    }
    return 0;
}
