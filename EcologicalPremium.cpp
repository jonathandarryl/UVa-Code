#include<iostream>

using namespace std;

int main(void){
	int testcase;
	int numoffarmer;
	int size[20];
	int animal[20];
	int friendly[20];
	int sum;
	cin>>testcase;
	for(int i=0;i<testcase;i++){
		sum = 0;
		cin>>numoffarmer;
		for(int j=0;j<numoffarmer;j++){
			cin>>size[j]>>animal[j]>>friendly[j];
			sum+=(size[j]*friendly[j]);
		}
		cout<<sum<<endl;
	}
	return 0;
}