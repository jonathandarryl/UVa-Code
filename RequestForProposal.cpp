#include<iostream>
#include<string>
using namespace std;

int main(void){
    string name, dummy, memorize;
    bool first = true;
    int compliance, req, company, max, counter, currentcompliance;
    double price, min_price;
    counter = 1;
    while(true){
        cin>>req>>company;
        if(req == company && company == 0)
            return 0;
        if(!first)
            cout<<endl;
        first = false;
        getline(cin,dummy);
        for(int i=0;i<req;i++){
            getline(cin,dummy);
        }
        min_price = 2147483640;
        currentcompliance = -1;
        for(int i=0;i<company;i++){
            getline(cin,name);
            cin>>price;
            cin>>compliance;
            if(compliance>currentcompliance){
                currentcompliance = compliance;
                min_price = price;
                memorize = name;
            }
            if(compliance == currentcompliance && price<min_price){
                min_price = price;
                memorize = name;
            }
            getline(cin,dummy);
            for(int i=0;i<compliance;i++)
                getline(cin,dummy);
        }
        cout<<"RFP #"<<counter<<endl;
        cout<<memorize<<endl;

        counter++;
    }
    return 0;
}
