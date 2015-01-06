#include<map>
#include<vector>
#include<iostream>
using namespace std;

int main(void){
    int input;
    map<int,int> maps;
    vector<int> order;
    bool found;
    while(cin>>input){
        maps[input]++;
        if(order.empty())
            order.push_back(input);
        else{
            found = false;
            for(int i=0;i<order.size();i++){
                if(order.at(i)==input){
                    found = true;
                    break;
                }
            }
            if(!found)
                order.push_back(input);
        }
    }
    for(int i=0;i<order.size();i++){
        cout<<order.at(i)<<" "<<maps[order.at(i)]<<endl;

    }

    return 0;
}
