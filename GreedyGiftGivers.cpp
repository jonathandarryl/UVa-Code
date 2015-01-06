#include<iostream>
#include<string>
using namespace std;
struct people{
    string name;
    int gold;
};
int main(void){
    bool first = true;
    int num, give,howmany,remember;
    string search;
    people peeps[10];
    while(cin>>num){
        if(!first)
            cout<<endl;
        first = false;
        for(int i=0;i<num;i++){
            cin>>peeps[i].name;
            peeps[i].gold = 0;
        }
        for(int i=0;i<num;i++){
            cin>>search>>give>>howmany;
            for(int j=0;j<num;j++){
                if(search == peeps[j].name){
                    if(howmany){
                        peeps[j].gold -= give;
                        peeps[j].gold+=give%howmany;
                    }
                }
            }
            for(int j=0;j<howmany;j++){
                cin>>search;
                for(int k=0;k<num;k++)
                if(search == peeps[k].name)
                    peeps[k].gold+=give/howmany;
            }
        }
        for(int i=0;i<num;i++)
            cout<<peeps[i].name<<" "<<peeps[i].gold<<endl;


    }

    return 0;
}
