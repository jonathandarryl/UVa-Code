#include<map>
#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int test, length;
    string input, input1;
    map<string,char> dict;
    dict[".-"] = 'A';
    dict["-..."] = 'B';
    dict["-.-."] = 'C';
    dict["-.."] = 'D';
    dict["."] = 'E';
    dict["..-."] = 'F';
    dict["--."] = 'G';
    dict["...."] = 'H';
    dict[".."] = 'I';
    dict[".---"] = 'J';
    dict["-.-"] = 'K';
    dict[".-.."] = 'L';
    dict["--"] = 'M';
    dict["-."] = 'N';
    dict["---"] = 'O';
    dict[".--."] = 'P';
    dict["--.-"] = 'Q';
    dict[".-."] = 'R';
    dict["..."] = 'S';
    dict["-"] = 'T';
    dict["..-"] = 'U';
    dict["...-"] = 'V';
    dict[".--"] = 'W';
    dict["-..-"] = 'X';
    dict["-.--"] = 'Y';
    dict["--.."] = 'Z';
    dict["-----"] = '0';
    dict[".----"] = '1';
    dict["..---"] = '2';
    dict["...--"] = '3';
    dict["....-"] = '4';
    dict["....."] = '5';
    dict["-...."] = '6';
    dict["--..."] = '7';
    dict["---.."] = '8';
    dict["----."] = '9';
    dict[".-.-.-"] = '.';
    dict["--..--"] = ',';
    dict["..--.."] = '?';
    dict[".----."] = '\'';
    dict["-.-.--"] = '!';
    dict["-..-."] = '/';
    dict["-.--."] = '(';
    dict["-.--.-"] = ')';
    dict[".-..."] = '&';
    dict["---..."] = ':';
    dict["-.-.-."] = ';';
    dict["-...-"] = '=';
    dict[".-.-."] = '+';
    dict["-....-"] = '-';
    dict["..--.-"] = '_';
    dict[".-..-."] = '"';
    dict[".--.-."] = '@';
    cin>>test;
    getline(cin,input);
    for(int i=1;i<=test;i++){
        getline(cin,input);
        cout<<"Message #"<<i<<endl;
        length = input.length();
        input1.clear();
        for(int j=0;j<length;j++){
            if(input1.empty()){
                if(input.at(j) ==' ')
                    cout<<" ";
                else
                    input1 = input.at(j);
            }
            else{
                    if(input.at(j)!=' ')
                    input1 = input1 + input.at(j);
                else{
                    cout<<dict[input1];
                    input1.clear();
                }
            }

        }
        if(input1.length()>0)
            cout<<dict[input1];
        cout<<endl;
        if(i!=test)
            cout<<endl;
    }
    return 0;
}
