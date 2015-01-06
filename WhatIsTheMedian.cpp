#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    long long value[10002];
    int counter, test;
    counter = 0;

    while(cin>>value[counter]){
        counter++;
        stable_sort(value, value+counter);

        if(counter%2==1)
            cout<<value[counter/2];
        else
            cout<<(value[counter/2]+value[counter/2-1])/2;
        cout<<endl;
        //for(int i=0;i<counter;i++)
          //  cout<<" "<<value[i]<<" ";
    }


}
