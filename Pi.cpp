#include<math.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int gcd(int,int);

int main(void){
    int array[50];
    int test, counter;
    double pi;
    while(true){
        cin>>test;
        if(test == 0)
            break;
        for(int i=0;i<test;i++)
            cin>>array[i];
        counter = 0;
        for(int i=0;i<test-1;i++)
            for(int j=i+1;j<test;j++)
                if(gcd(array[i],array[j])==1)
                    counter++;
        if(counter == 0)
            cout<<"No estimate for this data set."<<endl;
        else{
            pi = 6*test*(test-1)*0.5/counter;
            pi = sqrt(pi);
            printf("%.6lf\n",pi);
        }

    }

    return 0;
}

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}
