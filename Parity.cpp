#include<iostream>

using namespace std;
void parity(int);
int par(int);
int main(){
    int i;
    while(cin>>i){
        if(i==0)
            break;
        cout<<"The parity of ";
        parity(i);
        cout<<" is "<<par(i)<<" (mod 2)."<<endl;

    }

    return 0;
}

void parity(int num){
    if(num>0){
        parity(num/2);
        cout<<num%2;
    }
}

int par(int num){
    int counter = 0;
    while(num>0){
        if(num%2==1)
            counter++;
        num/=2;
    }
    return counter;
}
