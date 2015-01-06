#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;

int main(void){
    map<string, double> forest;

    int test;
    double counter;
    cin>>test;
    string dummy;
    getline(cin, dummy);
    getline(cin,dummy);
    for(int i=0;i<test;i++){
        forest.clear();
        counter = 0;
        while(getline(cin,dummy)){
            if(dummy.length()==0)
                break;
            forest[dummy]++;
            counter++;
        }
        counter/=100;
        for(map<string, double>::iterator it = forest.begin(); it!=forest.end();it++)
            printf("%s %.4lf\n", ((string)it->first).c_str(), (it->second)/counter);
        if(i!=test-1)
            cout<<endl;
    }

    return 0;
}
