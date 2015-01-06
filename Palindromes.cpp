#include<map>
#include<string.h>
#include<iostream>
using namespace std;

int main(void){
    map<char,char> mirror;
    mirror['A']='A';
    mirror['E']='3';
    mirror['H']='H';
    mirror['I'] = 'I';
    mirror['j'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';
    string input1, input2;
    bool isMirror, isPal, first = true;
    int length;
    while(cin>>input1){
        if(first)
            first = false;
        else
            cout<<endl;
        length = input1.length();
        input2 = input1.at(length-1);
        for(int i=length-2;i>=0;i--){
            input2 = input2 + input1.at(i);
        }
        isPal = false;
        if(input2 == input1)
            isPal = true;
        input2 = mirror[input1.at(length-1)];
        for(int i=length-2;i>=0;i--)
            input2 = input2 + mirror[input1.at(i)];
        isMirror = false;
        if(input2 == input1)
            isMirror = true;
        if(isMirror && isPal)
            cout<<input1<<" -- is a mirrored palindrome."<<endl;
        else if(isMirror)
            cout<<input1<<" -- is a mirrored string."<<endl;
        else if(isPal)
            cout<<input1<<" -- is a regular palindrome."<<endl;
        else
            cout<<input1<<" -- is not a palindrome."<<endl;
    }
    return 0;
}
