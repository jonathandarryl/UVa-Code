#include<iostream>
#include<string>

using namespace std;
char convert(char);
int main(void){
    string decodes;
    while(getline(cin,decodes)){
        for(int i=0;i<decodes.length();i++){
            cout<<convert(decodes.at(i));
        }
        cout<<endl;
    }

    return 0;
}

char convert(char decode){
    int asciivalue;
    asciivalue = (int) decode - 7;
    return (char) asciivalue;
}
