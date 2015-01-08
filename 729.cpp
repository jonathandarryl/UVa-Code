#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int test[16];
    int N,K, testcase;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>N>>K;
        for(int j=0;j<N-K;j++)
            test[j] = 0;
        for(int j=N-K;j<N;j++)
            test[j] = 1;
        do {
            for(int j=0;j<N;j++)
                cout<<test[j];
                cout<<endl;
        } while ( next_permutation (test,test+N) );
    }
    return 0;
}
