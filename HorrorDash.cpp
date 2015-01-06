#include<iostream>

using namespace std;

int main(void){
	int testcase, max, student;
	int speed[100];
	cin>>testcase;
	for(int i=1;i<=testcase;i++){
		max = 0;
		cin>>student;
		for(int j=0;j<student;j++){
			cin>>speed[j];
			if(speed[j]>max)
				max = speed[j];
		}
		cout<<"Case "<<i<<": "<<max<<endl;
	}
	return 0;
}