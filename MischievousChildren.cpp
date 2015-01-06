#include<iostream>
using namespace std;

int main(void){
    int test;
    unsigned long int permutation;
    int freq[26];
    string input;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>input;
        for(int j=0;j<26;j++)
            freq[j]=0;
        for(int j=0;j<input.length();j++)
            freq[(int) input.at(j) - 65]++;
        permutation = 1;
            if(input.length()<=12)
                for(int j=2;j<=input.length();j++)
                    permutation*=j;
            else
                for(int j=2;j<=12;j++)
                    permutation*=j;
            cout<<permutation<<"<<Permutation";
        for(int j=0;j<26;j++){
            while(freq[j]>1){
                permutation/=freq[j];
                freq[j]--;
            }
        }
        for(int j=13;j<=input.length();j--){
            permutation*=j;
        }
        cout<<"Data set "<<i<<": ";
        cout<<permutation<<endl;
    }
}
