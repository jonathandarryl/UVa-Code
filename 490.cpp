#include<string.h>
#include<iostream>
using namespace std;

int main(void){
    string sent[101];
    int counter,max;
    max = counter = 0;
    while(getline(cin,sent[counter])){
        if(sent[counter].length()>max)
            max = sent[counter].length();
        counter++;
    }
    for(int i=0;i<max;i++){
        for(int j=counter-1;j>=0;j--){
            if(sent[j].length()>i){
                cout<<sent[j].at(i);
            }
            else if(sent[j].length()<=i)
                cout<<" ";
        }
        cout<<endl;
    }

}
