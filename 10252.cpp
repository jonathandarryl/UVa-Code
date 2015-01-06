#include<map>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(void){
    map<char,int> map1;
    map<char,int> map2;
    string a,b;
    int length;
    while(getline(cin,a) && getline(cin,b)){
        map1.clear();
        map2.clear();
        length = a.length();
        for(int i=0;i<length;i++)
            map1[a.at(i)]++;
        length = b.length();
        for(int i=0;i<length;i++)
            map2[b.at(i)]++;
        for(char i='a';i<='z';i++){
            if(map1[i] && map2[i]){
                length = min(map1[i],map2[i]);
                for(int j=0;j<length;j++){
                    cout<<i;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

