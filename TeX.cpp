#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	string input;
	int i;
	bool haskutip = false;
	while(getline(cin, input)){
		for(i = 0;i < input.size();i++){
			if(input[i] == '"'){
				if(haskutip){
					haskutip = false;
					cout<<"``";
				}
				else{
					haskutip = true;
					cout<<
				}
			
			
			}
			else
				cout<<input[i];
		}
		cout<<endl;
	}

	return 0;
}