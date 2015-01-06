#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int testcase, salary, tax;

    cin>>testcase;

    for(int i=1;i<=testcase;i++){
        tax = 0;
        cin>>salary;
        if(salary>=1180000){
            tax = 150000;
            tax+=ceil((double)(salary-1180000)/4.0);
        }
        else if(salary>=880000){
            tax = 90000;
            tax+=ceil((double)(salary-880000)/5.0);
        }
        else if(salary>=480000){
            tax = 30000;
            tax+=ceil((double)(salary-480000)*3.0/20);
        }
        else if(salary>180000){
            tax=ceil((double)(salary-180000)/10.0);
            if(tax<2000)
                tax = 2000;
        }
        cout<<"Case "<<i<<": "<<tax<<endl;
    }
    return 0;
}
