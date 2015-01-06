#include <iostream>

using namespace std;

int main(){
	int i,j, carry, tempi, tempj, hascarry;


	while(true){
		cin>>i>>j;
		if(i==0 && j==0)
			return 0;
      carry = 0;
      hascarry = 0;
      while(i!=0 || j!=0){
		tempi = i%10;
        tempj = j%10;
        if(i!=0)
		i/=10;
		if(j!=0)
        j/=10;
        if((hascarry==0 && (tempi+tempj)>9) ||(hascarry==1 && tempi + tempj>8)){
          carry++;
          hascarry = 1;
        }
        else
          hascarry = 0;
      }
      if(carry==0){
        cout << "No carry operation.";
      }
      else if(carry==1){
        cout << "1 carry operation.";
      }
      else
        cout<< carry<<" carry operations.";
		cout<<endl;
    }
}
