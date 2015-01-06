#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    long long squares[101];
    squares[1] = 1;
    for(int i=2;i<=100;i++){
        squares[i] = squares[i-1]+(int)pow(i,2);
    }
    int input;
    while(cin>>input && input){
        cout<<squares[input]<<endl;
    }
    return 0;
}
