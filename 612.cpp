#include<map>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
map<string,int> sorts;
bool compsort(string a, string b){
    return sorts[a]<sorts[b];
}
int main(void){
    int test, length, num, counter;
    cin>>test;
    string arr[101];
    while(test--){
        cin>>length>>num;
        for(int i=0;i<num;i++){
            cin>>arr[i];
            counter = 0;
            if(!sorts[arr[i]]){
                for(int j=0;j<length-1;j++){
                    for(int k=j+1;k<length;k++)
                        if(arr[i].at(j)>arr[i].at(k))
                            counter++;
                }
                sorts[arr[i]] = counter;
            }
        }
        stable_sort(arr,arr+num, compsort);
        for(int i=0;i<num;i++)
            cout<<arr[i]<<endl;
        if(test)
            cout<<endl;
    }
    return 0;
}
