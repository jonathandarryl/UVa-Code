#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
    string input;
    stack<char> strstack;
    int test;
    cin>>test;
    getline(cin,input);
    for(int i=0;i<test;i++){
        getline(cin,input);
        for(int j=0;j<input.length();j++){
            if(input.at(j)=='(' || input.at(j)=='[')
                strstack.push(input.at(j));
            else if(!strstack.empty() && ((input.at(j) == ')' && strstack.top() == '(' )|| (input.at(j) ==']' && strstack.top() == '[')))
                strstack.pop();
            else if(input.at(j)==')' || input.at(j)==']')
                strstack.push(input.at(j));
        }
        if(strstack.empty())
            cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
            while(!strstack.empty())
                strstack.pop();
        }

    }
    return 0;
}
