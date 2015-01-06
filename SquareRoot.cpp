#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int test;
    unsigned long long a;

    cin>>test;
    for(int i=0;i<test;i++){
        cin>>a;
        cout<<(unsigned long int)sqrt(a)<<endl;
    }
    return 0;
}
