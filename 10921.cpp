#include<iostream>
#include<string>
using namespace std;
int convert(char);

int main(void){
    string telephone;
    while(getline(cin,telephone)){
        for(int i=0;i<telephone.length();i++){
            if((int)telephone.at(i)>=65 && (int)telephone.at(i)<=90){
                cout<<convert(telephone.at(i));
            }
            else
                cout<<telephone.at(i);
        }
        cout<<endl;

    }

    return 0;
}

int convert(char converted){
    switch(converted){
        case 'A': case 'B': case 'C':
            return 2;
        case 'D': case 'E': case 'F':
            return 3;
        case 'G': case 'H': case 'I':
            return 4;
        case 'J': case 'K': case 'L':
            return 5;
        case 'M': case 'N': case 'O':
            return 6;
        case 'P': case 'Q': case 'R': case'S':
            return 7;
        case 'T': case 'U': case 'V':
            return 8;
        case 'W': case 'X': case 'Y': case 'Z':
            return 9;

    }
}
