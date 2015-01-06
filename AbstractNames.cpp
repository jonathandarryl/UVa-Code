#include<iostream>
#include<string.h>
using namespace std;
bool vowel(char a){
    return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}
int main(void){
    int test;
    bool mut;
    string name1,name2;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>name1>>name2;
        mut = true;
        if(name1.length()!=name2.length())
            mut = false;
        else{
            for(int j=0;j<name1.length();j++){
                if(!vowel(name1.at(j))){
                    if(name1.at(j)!=name2.at(j) || vowel(name2.at(j))){
                        mut = false;
                        break;
                    }
                }
                if(vowel(name1.at(j)) && !vowel(name2.at(j)))
                    mut = false;
            }
        }
        if(mut)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
