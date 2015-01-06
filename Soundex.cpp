#include<string>
#include<iostream>
using namespace std;

int main(void){
    string input;
    int repeating;
    while(cin>>input){
        repeating = 0;
        for(int i=0;i<input.length();i++){
            switch(input.at(i)){
                case 'B': case'F': case'P': case'V':{
                    if(repeating!=1)
                        cout<<"1";
                    repeating = 1;
                    break;
                }
                case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':{
                    if(repeating!=2)
                        cout<<"2";
                    repeating = 2;
                    break;
                }
                case 'D': case 'T':{
                    if(repeating!=3)
                        cout<<"3";
                    repeating = 3;
                    break;
                }
                case 'L':{
                    if(repeating!=4)
                        cout<<"4";
                    repeating = 4;
                    break;
                }
                case 'M': case 'N':{
                    if(repeating!=5)
                        cout<<"5";
                    repeating = 5;
                    break;
                }
                case 'R':{
                    if(repeating!=6)
                        cout<<"6";
                    repeating = 6;
                    break;
                }
                default:{
                    repeating = 0;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
