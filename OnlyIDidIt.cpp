#include<map>
#include<set>
#include<iostream>
using namespace std;

int main(void){
    map<int,int> did;
    set<int> set1;
    set<int> set2;
    set<int> set3;
    int max,test,input,num;
    cin>>test;

    for(int i=1;i<=test;i++){
        cin>>input;
        for(int j=0;j<input;j++){
            cin>>num;
            did[num]++;
        }
        cin>>input;
        for(int j=0;j<input;j++){
            cin>>num;
            did[num]+=3;
        }
        cin>>input;
        for(int j=0;j<input;j++){
            cin>>num;
            did[num]+=5;
        }
        for(map<int,int>::iterator it = did.begin();it!=did.end();it++){
            if(it->second == 1)
                set1.insert(it->first);
            else if(it->second == 3)
                set2.insert(it->first);
            else if(it->second == 5)
                set3.insert(it->first);
        }
        max = set1.size();
        cout<<"Case #"<<i<<":"<<endl;
        if(max<set2.size())
            max = set2.size();
        if(max<set3.size())
            max = set3.size();
        if(set1.size() == max){
            cout<<"1 "<<max;
            for(set<int>::iterator it1 = set1.begin();it1!=set1.end();it1++)
                cout<<" "<<*it1;
            cout<<endl;
        }
        if(set2.size() == max){
            cout<<"2 "<<max;
            for(set<int>::iterator it1 = set2.begin();it1!=set2.end();it1++)
                cout<<" "<<*it1;
            cout<<endl;
        }
        if(set3.size() == max){
            cout<<"3 "<<max;
            for(set<int>::iterator it1 = set3.begin();it1!=set3.end();it1++)
                cout<<" "<<*it1;
            cout<<endl;
        }
        set1.clear();
        set2.clear();
        set3.clear();
        did.clear();
    }
    return 0;
}
