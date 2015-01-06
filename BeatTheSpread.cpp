#include<iostream>

using namespace std;

int main(void){
	int sum, dif, n, x, y, temp;
cin>>n;
	for(int i=0;i<n;i++){
		cin>>sum>>dif;
		x = (sum+dif)/2;
		y = sum-x;
		if(x<0 || y<0 || (sum+dif)%2==1)
			cout<<"impossible"<<endl;
		else	
			cout<<x<<" "<<y<<endl;  
	}
	return 0;
}