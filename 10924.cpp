#include<string>
#include<iostream>

using namespace std;
int convert(char);
int main(void){
    bool isPrime;
    string test;
    int total;
    while(cin>>test){
        isPrime = true;
        total = 0;
        for(int i=0;i<test.length();i++)
            total+=convert(test.at(i));
        for(int i=2;i<total;i++){
            if(total%i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout<<"It is a prime word."<<endl;

        else
            cout<<"It is not a prime word."<<endl;
    }
    return 0;
}

int convert(char converted){

    if((int) converted >96){
        return (int) converted - 96;
    }
    else{
        return (int) converted - 38;
    }
}
