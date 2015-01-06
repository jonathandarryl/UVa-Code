#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31};

void prime_ring(int i, vector<int> x,int iter){
    if(x.size() == i){
        if(binary_search(prime,prime+11,x.at(i-1) + x.at(0))){
            for(int j=0;j<i-1;j++)
                cout<<x.at(j)<<" ";
            cout<<x.at(i-1)<<endl;
            x.clear();
        }
    }
    else{
        for(int j=2;j<=i;j++){
            //cout<<"j: "<<j<<" size x:"<<x.size()<<" iteration: "<<iter<<endl;
            if(binary_search(prime,prime+11,x.at(x.size()-1)+j)){
                bool have = false;
                for(int k=0;k<x.size();k++){
                    if(x.at(k)==j)
                        have = true;
                }
                if(!have){
                    x.push_back(j);
                    prime_ring(i,x,iter+1);
                    x.pop_back();
                }

            }
        }
    }
    return;
}
int main(void){
    vector<int> x;
    bool first = true;
    int input, counter = 1;
    while(cin>>input){
        if(first)
            first = false;
        else{
            cout<<endl;
        }
        cout<<"Case "<<counter++<<":"<<endl;
        x.push_back(1);
        prime_ring(input,x,0);
        x.clear();
    }
    return 0;
}
