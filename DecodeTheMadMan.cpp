#include<string>
#include<iostream>
using namespace std;

int main(void){
    string input;
    while(getline(cin,input)){
        for(int i=0;i<input.length();i++){
            switch(input.at(i)){
                case 'e': case 'E':
                    cout<<"q";
                    break;
                case 'r': case 'R':
                    cout<<"w";
                    break;
                case 'T': case 't':
                    cout<<"e";
                    break;
                case 'y': case 'Y':
                    cout<<"r";
                    break;
                case 'u': case 'U':
                    cout<<"t";
                    break;
                case 'i': case 'I':
                    cout<<"y";
                    break;
                case 'o': case 'O':
                    cout<<"u";
                    break;
                case 'p': case 'P':
                    cout<<"i";
                    break;
                case '[': case '{':
                    cout<<"o";
                    break;
                case ']': case '}':
                    cout<<"p";
                    break;
                case '\\': case '|':
                    cout<<"[";
                    break;
                case 'd': case 'D':
                    cout<<"a";
                    break;
                case 'f': case 'F':
                    cout<<"s";
                    break;
                case 'g': case 'G':
                    cout<<"d";
                    break;
                case 'h': case 'H':
                    cout<<"f";
                    break;
                case 'j': case 'J':
                    cout<<"g";
                    break;
                case 'k': case 'K':
                    cout<<"h";
                    break;
                case 'l': case 'L':
                    cout<<"j";
                    break;
                case ';': case ':':
                    cout<<"k";
                    break;
                case '\'': case '"':
                    cout<<"l";
                    break;
                case 'c': case 'C':
                    cout<<"z";
                    break;
                case 'v': case 'V':
                    cout<<"x";
                    break;
                case 'b': case 'B':
                    cout<<"c";
                    break;
                case 'N': case 'n':
                    cout<<"v";
                    break;
                case 'm': case 'M':
                    cout<<"b";
                    break;
                case ',': case '<':
                    cout<<"n";
                    break;
                case '.': case '>':
                    cout<<"m";
                case ' ':
                    cout<<" ";
                    break;
            }
        }
        cout<<endl;
    }
    return 0;
}
