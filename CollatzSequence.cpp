#include<iostream>
using namespace std;

int main(void){
    long long A, L;
    int counter;
    int i = 1;
    while(cin>>A>>L && A>0 && L>0){
        counter = 0;
        cout<<"Case "<<i<<": A = "<<A<<", limit = "<<L<<", number of terms = ";
        while(A!=1 && A<=L){
            counter++;
            if(A%2==1)
                A = A*3 + 1;
            else
                A/=2;
        }
        if(A==1)
            counter++;
        cout<<counter<<endl;
        i++;
    }

}
