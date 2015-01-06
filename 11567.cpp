#include<iostream>
using namespace std;

int main(void){
    long long input;
    int counter;
    while(cin>>input){
        if(input<=3)
            cout<<input;
        else{
            counter = 0;
            while(input!=1){
                if(input%2==0)
                    input/=2;
                else{
                    if(((input-1) %4 == 0) || input == 3)
                        input--;
                    else
                        input++;
                }
                counter++;
            }
            cout<<++counter;
        }
        cout<<endl;
    }
    return 0;
}
