#include<iostream>
#include<map>
using namespace std;

int main(void){
    int test,testcase, price;
    cin>>test>>testcase;
    map<string,int> job;
    string input;
    for(int i=0;i<test;i++){
        cin>>input;
        cin>>price;
        job[input] = price;
    }
    long long sum;
    for(int i=0;i<testcase;i++){
        sum = 0;
        while(cin>>input){
            if(input==".")
                break;
            if(job.find(input)!=job.end())
                sum+=job[input];
        }
        cout<<sum<<endl;
    }


}
