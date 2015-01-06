#include<set>
#include<map>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

int main(void){
    string input, sorted;
    set<string> dict;
    map<string,string> in;
    while(true){
        getline(cin,input);
        if(input == "XXXXXX")
            break;

        sorted = input;
        sort(input.begin(), input.end());
        in[sorted] = input;
        dict.insert(input);
    }
    bool found;
    while(true){
        getline(cin,input);
        if(input == "XXXXXX")
            break;
        found = false;
        sort(input.begin(),input.end());
        for(map<string,string>::iterator it = in.begin();it!=in.end();it++)
            if(it->second == input){
                cout<<it->first<<endl;
                found = true;
            }
        if(!found)
            cout<<"NOT A VALID WORD"<<endl;
        cout<<"******"<<endl;
    }

    return 0;
}
