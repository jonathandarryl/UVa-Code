#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct country_t{
    char name[100];
    int girls;

};
bool compare(string,string);
int main(void){
    int test,counter;
    char dummy[100];
    string testing;
    bool written;
    counter = 0;
    cin>>test;
    country_t country[2000];
    for(int i=0;i<test;i++){
        scanf("%s",dummy);
        written = false;
        for(int j=0;j<counter;j++){
            if(strcmp(country[j].name,dummy)==0){
                country[j].girls++;
                written = true;
                break;
            }
        }
        if(!written){
            strcpy(country[counter].name , dummy);
            country[counter].girls = 1;
            counter++;
        }
        getline(cin,testing);
    }

    for (int j = 1; j < counter; j++) {
		bool is_sorted = true;
		for (int k = 0; k < counter-j; k++) {
			if (strcmp(country[k].name,country[k+1].name)>0) {
				country_t temp = country[k];
				country[k] = country[k+1];
				country[k+1] = temp;
				is_sorted = false;
			}
		}
		if (is_sorted) break;
    }
    for(int j=0;j<counter;j++){
        cout<<country[j].name<<" "<<country[j].girls<<endl;
    }



    return 0;
}

bool compare(string test1, string test2){
    int max = (test1.length(), test2.length());
    for(int i=0;i<max;i++){
        if(test1.at(i)!=test2.at(i))
            if((int)test2.at(i)<(int)test1.at(i))
                return false;
    }
    return true;
}
