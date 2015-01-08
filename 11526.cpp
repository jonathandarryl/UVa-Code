#include<iostream>
#include<stdio.h>
using namespace std;


long long H(int);

int main(void){
    int n, test;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&n);
        printf("%li\n",H(n));
    }


    return 0;
}


long long H(int n){
      long long res = 0;
     for(int i = 1; i <= n;i++){
            res+=n/i;
      }
     return res;

}
