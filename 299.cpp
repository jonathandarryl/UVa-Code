#include<iostream>
using namespace std;

int main(void){
    int length, train[51];
    int test, swap,temp;
    bool is_sorted;
    cin>>test;
    for(int i=0;i<test;i++){
        swap = 0;
        cin>>length;
        for(int j=0;j<length;j++)
            cin>>train[j];
        for (int k = 1; k < length; k++) {
            is_sorted = true;
            for (int j = 0; j < length-k; j++) {
                if (train[j] > train[j+1]) {
                    temp = train[j];
                    train[j] = train[j+1];
                    train[j+1] = temp;
                    is_sorted = false;
                    swap++;
                }
            }
            if (is_sorted)
                break;
        }
        cout<<"Optimal train swapping takes "<<swap<<" swaps."<<endl;
    }
    return 0;
}


