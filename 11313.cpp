#include<iostream>
using namespace std;

int main(void){
    int test, tcase;
    int newcola, total, empty, numchef;
    cin>>tcase;
    for(int i=0;i<tcase;i++){
        cin>>test>>numchef;
        total = test/numchef;
        empty = test/numchef + test%numchef;

        while(empty>=numchef){
            newcola = empty/numchef;
            empty = empty%numchef + newcola;
            total+=newcola;
        }
        if(empty == 1){
            cout<<total<<endl;
        }
        else
            cout<<"cannot do this"<<endl;
    }
    return 0;
}
