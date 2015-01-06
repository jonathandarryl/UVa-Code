#include<iostream>
#include<string>
using namespace std;

int main(void){
    int counter;
    string input;
    counter = 1;
    while(true){
        cin>>input;
        if(input == "#")
            return 0;
        cout<<"Case "<<counter<<": ";
        if(input == "HELLO")
            cout<<"ENGLISH"<<endl;
        else if(input == "HOLA")
            cout<<"SPANISH"<<endl;
        else if(input == "HALLO")
            cout<<"GERMAN"<<endl;
        else if(input == "BONJOUR")
            cout<<"FRENCH"<<endl;
        else if(input == "CIAO")
            cout<<"ITALIAN"<<endl;
        else if(input == "ZDRAVSTVUJTE")
            cout<<"RUSSIAN"<<endl;
        else
            cout<<"UNKNOWN"<<endl;
        counter++;
    }
    return 0;
}
