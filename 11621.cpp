#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main(void){
    vector<long long> myint;
    long long temp;
    long long input;
    for(long long i=0;i<=31;i++)
        for(long long j=0;j<20;j++){
            temp = pow(2,i)*pow(3,j);
            if(temp>0)
                myint.push_back(temp);
        }
    sort(myint.begin(),myint.end());

    vector<long long>::iterator it;
    it = myint.begin();

    while(cin>>input && input){
        if(binary_search(myint.begin(),myint.end(),input))
            cout<<input<<endl;
        else{
            it = upper_bound(myint.begin(),myint.end(),input);
            cout<<*it<<endl;
        }

    }
    return 0;
}
