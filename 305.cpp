#include<iostream>
using namespace std;

int main(void){
    int arr[13] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
    int k;
    while(cin>>k && k){
        cout<<arr[k-1]<<endl;
    }
}
