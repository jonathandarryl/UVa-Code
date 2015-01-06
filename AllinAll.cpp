#include<string>
#include<iostream>
using namespace std;

int main(void){
    string input1, input2;
    int counter1,counter2;
    while(cin>>input1>>input2){
        counter1 = counter2 = 0;
        while(counter1<input1.length() && counter2<input2.length()){
            while(input1.at(counter1)!=input2.at(counter2)){
                counter2++;
                if(counter2 == input2.length())
                    break;
            }
            if(counter2 == input2.length())
                break;
            counter1++;
            counter2++;
        }
        if(counter1 == input1.length())
            cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
        }

    }
    return 0;
}
