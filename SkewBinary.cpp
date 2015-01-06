#include<iostream>
#include<math.h>
#include<string>

using namespace std;

int main(void){
	string number;
	int sum;
	
	while(true){
		cin>>number;
		if(number.size() == 1 && number.at(0)=='0')
			break;
		sum = 0;
		for(int i=0;i < number.length();i++){
			switch (number.at(number.length()-1-i))
			{
				case('0'):
					break;
				case('1'):
					sum+=1*((int)pow(2.0,(i+1))-1);
					break;
				case('2'):
					sum+=2*((int)pow(2.0,(i+1))-1);
					break;
			}
			
	
		}
		cout<<sum<<endl;
	}
	return 0;
}