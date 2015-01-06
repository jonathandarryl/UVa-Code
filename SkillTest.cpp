#include<iostream>

using namespace std;

int main(void){
    int testcase;
    int number;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>number;
        number*=63;
        number+=7492;
        number*=5;
        number-=498;
        number/=10;
        number = number%10;
        if(number<0)
            number*=-1;
        cout<<number<<endl;
    }
    return 0;
}
