#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    bool self[1000001];
    memset(self,true,sizeof self);
    int num,temp;
    for(int i=1;i<=1000000;i++){
        num = i;
        temp = num;
        while(num>0){
            temp+=num%10;
            num/=10;
        }
        if(temp<1000001)
            self[temp] = false;
    }
    for(int i=1;i<=1000000;i++)
        if(self[i])
            cout<<i<<endl;
    return 0;
}
