#include<iostream>
using namespace std;

int main(void){
    int length, train[1001];
    int test, swap,temp;
    bool is_sorted;
    while(cin>>length){
        swap = 0;
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
        cout<<"Minimum exchange operations : "<<swap<<endl;
    }
    return 0;
}


