#include<map>
#include<iostream>
#include<string>
using namespace std;

int main(void){
    map<string,int> dict;
    string input, newstr;
    char in;
    int len;
    while(getline(cin,input)){
        len = input.length();
        for(int i=0;i<len;i++){
            if(input.at(i)>='A' && input.at(i)<='Z'){
                in = tolower(input.at(i));
                newstr = newstr + in;

            }
            else if(input.at(i)>='a' && input.at(i)<='z')
                newstr = newstr + input.at(i);
            else if(input.at(i)=='-' && i !=len-1)
                newstr = newstr+input.at(i);
            else if(newstr.length()>0 && input.at(i)!='-'){
                dict[newstr]++;
                newstr.clear();
            }
            if(i == len-1 && newstr.length()>0 && input.at(i)!='-'){
                dict[newstr]++;
                newstr.clear();
            }
        }
    }
    for(map<string,int>::iterator it = dict.begin(); it!=dict.end();it++)
        cout<<it->first<<endl;


}

