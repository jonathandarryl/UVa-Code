#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main(void){
    string words;
    int occur[128];
    int max;
    while(getline(cin,words)){
        max = 0;
        for(int i=0;i<128;i++)
            occur[i] = 0;
        for(int i=0;i<words.length();i++){
            if((int) words.at(i)>64 && (int) words.at(i)<128)
            occur[(int)words.at(i)]++;
            if(occur[(int)words.at(i)]>max)
                max = occur[(int) words.at(i)];

        }

        for(int i=65;i<122;i++){
            if(occur[i]==max)
                cout<<(char) i;

        }
        cout<<" "<<max<<endl;
    }
    return 0;
}
