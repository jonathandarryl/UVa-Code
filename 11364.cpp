#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int main(void){
    int test, array[20],stores;
    int median, total;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>stores;
        for(int j=0;j<stores;j++)
            cin>>array[j];
        total = 0;
        sort(array,array+stores);

        for(int j=0;j<stores-1;j++)
            total += array[j+1]-array[j];
        total+=array[stores-1]-array[0];
        cout<<(int)total<<endl;
    }

    return 0;

}
