#include<iostream>
#include<math.h>

using namespace std;

int main(void){

    int test, needed;
    double x,y;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>x>>y;
        needed = ceil((x-2)/3) * ceil((y-2)/3);
        cout<<needed<<endl;
    }
    return 0;
}
