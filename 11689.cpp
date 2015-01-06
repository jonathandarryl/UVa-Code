#include<iostream>
using namespace std;

int main(void){
    int test, e,f,c, total, current, newsoda, remainder;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>e>>f>>c;
        total = 0;
        current = e+f;
        while(current>=c){
            newsoda = current/c;
            total+=newsoda;
            remainder = current%c;
            current = newsoda+remainder;
        }
        cout<<total<<endl;
    }

    return 0;
}
