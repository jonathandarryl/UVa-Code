#include<map>
#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int n,k;
    string sing,plur,in;
    map<string,string>irr;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>sing>>plur;
        irr[sing]=plur;
    }
    for(int i=0;i<k;i++){
        cin>>in;
        if(irr.find(in)!=irr.end())
            cout<<irr[in]<<endl;
        else{
            if(in.at(in.length()-1)=='y' && in.at(in.length()-2)!='a' && in.at(in.length()-2)!='e' && in.at(in.length()-2)!='i' && in.at(in.length()-2)!='o' && in.at(in.length()-2)!='u'){
                for(int i=0;i<in.length()-1;i++)
                    cout<<in.at(i);
                cout<<"ies"<<endl;
            }
            else if(in.at(in.length()-1)=='o' || in.at(in.length()-1)=='x' || in.at(in.length()-1)=='s' || ((in.at(in.length()-2)=='c' || in.at(in.length()-2)=='s') && in.at(in.length()-1)=='h'))
                cout<<in<<"es"<<endl;
            else
                cout<<in<<"s"<<endl;
        }
    }
    return 0;
}
