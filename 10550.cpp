#include<iostream>

using namespace std;

int main(void){
    int start, dial1, dial2, dial3, total;
    while(true){

        cin>>start>>dial1>>dial2>>dial3;
        if(start==dial1 && dial1==dial2 && dial2 == dial3 && dial3 == 0)
            break;
        total = 1080;
        if(start<dial1)
            total+= 360-(dial1-start)*9;
        else
            total+= 360-((dial1*9) + (40-start)*9);

        if(dial1>dial2)
            total+= 360-(dial1-dial2)*9;
        else
            total+= 360-((40-dial2)*9 + dial1*9);

        if(dial2<dial3)
            total+= 360-((dial3-dial2)*9);
        else
            total+= 360-((dial3*9) + (40-dial2)*9);
        cout<<total<<endl;

    }
    return 0;
}
