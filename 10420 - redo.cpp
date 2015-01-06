#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int main(void){
    map<string,int> conq;
    int in;
    string dum;
    cin>>in;
    for(int i=0;i<in;i++){
        cin>>dum;
        conq[dum]++;
        getline(cin,dum);
    }
    for(map<string,int>::iterator it = conq.begin();it!=conq.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    return 0;
}
