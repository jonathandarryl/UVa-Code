#include<map>
#include<iostream>
using namespace std;

int main(void){
    int test,pair,pair2,max,counter;
    cin>>test;
    map<string,string> party;
    map<string,int> vote;
    string name, par,remember;
    for(int i=0;i<test;i++){
        cin>>pair;
        getline(cin,name);
        party.clear();
        vote.clear();
        for(int j=0;j<pair;j++){
            getline(cin,name);
            getline(cin,par);
            party[name]=par;
        }
        cin>>pair2;
        getline(cin,name);
        for(int j=0;j<pair2;j++){
            getline(cin,name);
            if(party.find(name)!=party.end()){
                vote[name]++;
            }
        }
        max = 0;
        for(map<string,int>::iterator it=vote.begin();it!=vote.end();it++){
            if(it->second>max)
                max = it->second;
        }
        counter = 0;
        for(map<string,int>::iterator it=vote.begin();it!=vote.end();it++){
            if(it->second==max){
                counter++;
                remember = party[it->first];
                if(counter>1){
                    remember = "tie";
                    break;
                }
            }
        }
        cout<<remember<<endl;
        if(i!=test-1)
            cout<<endl;
    }
    return 0;
}
