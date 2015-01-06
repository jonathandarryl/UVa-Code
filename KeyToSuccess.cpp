#include<map>
#include<iostream>
using namespace std;

int main(void){
    map<char,int> actual;
    map<char,int> decoded;
    map<char,char> key;
    map<char,int>::iterator rem, rem1;
    int input, max;
    string input1;
    cin>>input;
    getline(cin,input1);
    for(int i=0;i<input;i++){
        actual.clear();
        decoded.clear();
        key.clear();
        getline(cin,input1);
        getline(cin,input1);
        for(int j=0;j<input1.length();j++)
            actual[input1.at(j)]++;
        getline(cin,input1);
        for(int j=0;j<input1.length();j++)
            decoded[input1.at(j)]++;
        max = 1;
        while(max!=0){
            max = 0;
            for(map<char,int>::iterator it = actual.begin();it!=actual.end();it++)
                if(it->second > max){
                    max = it->second;
                    rem = it;
                }
            for(map<char,int>::iterator it = decoded.begin();it!=decoded.end();it++)
                if(it->second > max){
                    max = it->second;
                    rem1 = it;
                }
            key[rem1->first] = rem->first;
            rem->second = -1;
            rem1->second = -1;
        }
        for(int j=0;j<input1.length();j++)
            cout<<key[input1.at(j)];
        cout<<endl;
        if(i!=input-1)
            cout<<endl;
    }

    return 0;
}
