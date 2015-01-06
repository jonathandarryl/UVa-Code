#include<iostream>
using namespace std;

int main(void){
    int total,current_amt,wax,new_candle,remainder;
    while(cin>>current_amt>>wax){
        total = current_amt;
	while(current_amt >= wax)
	{
		new_candle = current_amt/wax;
		total = total + new_candle;
		remainder = current_amt%wax;
		current_amt = new_candle + remainder;

	}
        cout<<total<<endl;
    }

    return 0;
}

