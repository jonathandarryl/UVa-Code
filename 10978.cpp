#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main(void){
    string unsort[55],sorted[55],in;
    int test,take;
    vector<int> tes;
    vector<int>::iterator it;
    bool taken[55];
    int length[55];
    while(cin>>test && test){
        for(int i=0;i<test;i++){
            cin>>unsort[i]>>in;
            length[i] = in.length() - 1;
            tes.push_back(i);
        }
        for(int i=0;i<test;i++)
            taken[i]=false;
        int current = 0, counter;
        for(int i=0;i<test;i++){
            counter = 0;
            while(counter<length[i]){
                current++;
                counter++;
                if(current == tes.size())
                    current = 0;
            }
            sorted[tes[current]] = unsort[i];
            tes.erase(tes.begin()+current-1);

        }




        for(int i=0;i<test-1;i++)
            cout<<sorted[i]<<" ";
        cout<<sorted[test-1]<<endl;
    }
    return 0;
}
