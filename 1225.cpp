#include<iostream>

using namespace std;
void countdigit(int, int[]);
int main(void){
    int test,digit;
    int digitcounter[10];
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>digit;
        for(int j=0;j<10;j++)
            digitcounter[j] = 0;
        for(int j=1;j<=digit;j++)
            countdigit(j,digitcounter);
        for(int j=0;j<9;j++)
            cout<<digitcounter[j]<<" ";
        cout<<digitcounter[9]<<endl;
    }

    return 0;
}


void countdigit(int number,int digitcounter[]){
    while(number>0){
        digitcounter[number%10]++;
        number/=10;
    }
}
