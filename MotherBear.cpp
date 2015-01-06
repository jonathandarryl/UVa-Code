#include<iostream>
#include<string>

using namespace std;

int main(void){
    string str;
    bool isPalindrome;
    int len;
    while(getline(cin,str)){
        if(str == "DONE")
            return 0;
        isPalindrome = true;
        for(int i=0;i<str.length();i++){
            if((int)str.at(i)<65 || ((int)str.at(i)>90 && (int)str.at(i)<97) || (int)str.at(i)>122){
                str.erase(i,1);
                i--;
            }
            else if((int)str.at(i)>=97)
                str.at(i)-=32;
        }

        for(int i=0;i<str.length()/2;i++){
            if(str.at(i)!=str.at(str.length()-1-i)){
                isPalindrome = false;

                break;
            }
        }
        if(isPalindrome)
            cout<<"You won't be eaten!"<<endl;
        else
            cout<<"Uh oh.."<<endl;

    }
    return 0;
}

