#include<iostream>
using namespace std;
void insertion(int[]);
int main(void){
    int a[10] = {2,3,1,4,5,6,7,9,8,10};
    insertion(a);
    for(int i=0;i<10;i++){
        cout<<a[i];
    }
    return 0;
}


void insertion(int a[]){
    int next,j;
    for(int i=1;i<10;i++){

        for(j=i-1;j>=0 && a[j]>a[i];j--)
            a[j+1] = a[j];
        a[j+1] = a[i];
    }
}
