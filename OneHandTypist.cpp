#include<map>
#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    string input;
    map<char,char> dict;
    dict['~'] = '~';
    dict['!'] = '!';
    dict['@'] = '@';
    dict['#'] = '#';
    dict['$'] = 'Q';
    dict['%'] = 'J';
    dict['^'] = 'L';
    dict['&'] = 'M';
    dict['*'] = 'F';
    dict['('] = 'P';
    dict[')'] = '?';
    dict['_'] = '{';
    dict['+'] = '}';
    dict['Q'] = '$';
    dict['W'] = '%';
    dict['E'] = '^';
    dict['R'] = '>';
    dict['T'] = 'O';
    dict['Y'] = 'R';
    dict['U'] = 'S';
    dict['I'] = 'U';
    dict['O'] = 'Y';
    dict['P'] = 'B';
    dict['{'] = ':';
    dict['}'] = '+';
    dict['|'] = '|';
    dict['A'] = '&';
    dict['S'] = '*';
    dict['D'] = '(';
    dict['F'] = 'A';
    dict['G'] = 'E';
    dict['H'] = 'H';
    dict['J'] = 'T';
    dict['K'] = 'D';
    dict['L'] = 'C';
    dict[':'] = 'K';
    dict['"'] = '_';
    dict['Z'] = ')';
    dict['X'] = 'Z';
    dict['C'] = 'X';
    dict['V'] = '<';
    dict['B'] = 'I';
    dict['N'] = 'N';
    dict['M'] = 'W';
    dict['<'] = 'V';
    dict['>'] = 'G';
    dict['?'] = '"';
    dict['`'] = '`';
    dict['1'] = '1';
    dict['2'] = '2';
    dict['3'] = '3';
    dict['4'] = 'q';
    dict['5'] = 'j';
    dict['6'] = 'l';
    dict['7'] = 'm';
    dict['8'] = 'f';
    dict['9'] = 'p';
    dict['0'] = '/';
    dict['-'] = '[';
    dict['='] = ']';
    dict['q'] = '4';
    dict['w'] = '5';
    dict['e'] = '6';
    dict['r'] = '.';
    dict['t'] = 'o';
    dict['y'] = 'r';
    dict['u'] = 's';
    dict['i'] = 'u';
    dict['o'] = 'y';
    dict['p'] = 'b';
    dict['['] = ';';
    dict[']'] = '=';
    dict['\\'] = '\\';
    dict['a'] = '7';
    dict['s'] = '8';
    dict['d'] = '9';
    dict['f'] = 'a';
    dict['g'] = 'e';
    dict['h'] = 'h';
    dict['j'] = 't';
    dict['k'] = 'd';
    dict['l'] = 'c';
    dict[';'] = 'k';
    dict['\''] = '-';
    dict['z'] = '0';
    dict['x'] = 'z';
    dict['c'] = 'x';
    dict['v'] = ',';
    dict['b'] = 'i';
    dict['n'] = 'n';
    dict['m'] = 'w';
    dict[','] = 'v';
    dict['.'] = 'g';
    dict['/'] = '\'';
    dict[' '] = ' ';
    while(getline(cin,input)){
        for(int i=0;i<input.length();i++)
            cout<<dict[input.at(i)];
        cout<<endl;
    }

    return 0;
}
