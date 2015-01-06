#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    long long x, y, res, count;
    int test, counter;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>x>>y;
        y = y-x;
        if(y==0)
            cout<<"0"<<endl;
        else if(y==1)
            cout<<"1"<<endl;
        else{
            counter = 2;
            count = counter*counter;
            while(count<y){
                counter++;
                count = counter*counter;
            }
            if(y<=count-counter){
                counter = counter*2-2;
            }
            else
                counter = counter*2-1;
            cout<<counter<<endl;
        }

    }
    return 0;
}
