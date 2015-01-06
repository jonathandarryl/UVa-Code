#include<map>
#include<iostream>
using namespace std;

int main(void){
    string input, inputnum;
    int numcom;
    int numquery;
    map<string, int> value;
    double val;
    int ans, realans;
    bool guess;
    cin>>numcom>>numquery;
    for(int i=0;i<numcom;i++){
        cin>>input>>inputnum;
        if(inputnum.length()==3)
            val = (inputnum.at(0)-'0')*10 + inputnum.at(2)-'0';
        if(inputnum.length()==4)
            val = (inputnum.at(0)-'0')*100  + (inputnum.at(1)-'0')*10+ inputnum.at(3)-'0';

        value[input] = val;
    }
    for(int i=1;i<=numquery;i++){
        ans = 0;
        guess = false;
        while(true){
            cin>>input;
            if(input == "="){
                cin>>realans;
                if(ans == realans*10)
                    guess = true;
                break;
            }
            else if(input == ">"){
                cin>>realans;
                if(ans > realans*10)
                    guess = true;
                break;
            }
            else if(input == ">="){
                cin>>realans;
                if(ans >= realans*10)
                    guess = true;
                break;
            }
            else if(input == "<"){
                cin>>realans;
                if(ans<realans*10)
                    guess = true;
                break;
            }
            else if(input == "<="){
                cin>>realans;
                if(ans<=realans*10)
                    guess = true;
                break;
            }
            else if(input !="+"){
                ans +=value[input];
            }
        }
        //cout<<ans<<"  "<<realans<<endl<<endl;
        cout<<"Guess #"<<i<<" was ";
        if(guess)
            cout<<"correct."<<endl;
        else
            cout<<"incorrect."<<endl;
    }

}
