#include<iostream>
#include<stdio.h>
#include<bitset>
#include<vector>
using namespace std;
vector<int> primes;

bitset<4000> bs;

void sieve(){
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i=2;i<4000;i++)
        if(bs[i]){
            for(int j=i*i;j<4000;j*=i)
                bs[j] = 0;
            primes.push_back(i);
        }

}

int main(void){
    sieve();
    int num, TC;
    cin>>TC;
    for(int z=1;z<=TC;z++){
        cin>>num;
        int last = 0;
        int counter = 0;
        cout<<"Case #"<<z<<": "<<num<<" = ";
        for(int i=0;i<(int)primes.size();i++)
            if(num%primes[i]==0){
                last = primes[i];
                counter++;
                cout<<primes[i]<<" * "<<num/primes[i];
                if(counter==2)
                    break;
                cout<<" = ";
            }
        if(counter == 1){
            for(int i=last+1;i<num;i++)
                if(num%i==0){
                    cout<<i<<" * "<<num/i;
                    break;
                }
        }
        cout<<endl;
    }
    return 0;
}
