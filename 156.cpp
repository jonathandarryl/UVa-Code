#include<set>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

int main(void){
    set<string> sorted;
    set<string> unsorted;
    map<string, string> sortunsort;
    string input, temp;
    while(cin>>input){
        if(input == "#")
            break;
        temp = input;
        for(int i=0;i<input.length();i++)
            if(input.at(i)>='A' && input.at(i)<='Z')
                input.replace(i,1,1,input.at(i)+32);
        sort(input.begin(), input.end());
        if(sorted.empty()){
            sorted.insert(input);
            unsorted.insert(temp);
            sortunsort[input] = temp;
        }
        else if(sorted.find(input)==sorted.end()){
            sorted.insert(input);
            unsorted.insert(temp);
            sortunsort[input] = temp;
        }
        else{
            unsorted.erase(sortunsort[input]);
        }
    }
    for(set<string>::iterator it = unsorted.begin();it!=unsorted.end();it++)
        cout<<*it<<endl;
    return 0;
}
