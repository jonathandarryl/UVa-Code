#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int gcd(int,int);
int main(void){
    string in;
    int len, test, test1,test2;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>in;
        len = in.length();
        test1 = test2 = 0;
        for(int j=0;j<len;j++)
            test1+=(in.at(j)-'0')*(int)pow(2,len-j-1);
        cin>>in;
        len = in.length();
        for(int j=0;j<len;j++)
            test2+=(in.at(j)-'0')*(int)pow(2,len-j-1);

        cout<<"Pair #"<<i<<": ";
        if(gcd(test1,test2)>1)
            cout<<"All you need is love!"<<endl;
        else
            cout<<"Love is not all you need!"<<endl;
    }
    return 0;
}

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b,a%b));
}
