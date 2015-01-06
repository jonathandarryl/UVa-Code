#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    bool found, wrong, first = true;
    int input, j, temp;
    int arr[10];
    while(cin>>input && input){
        if(!first)
            cout<<endl;
        first = false;
        found = false;
        for(int i=1234;i<98765;i++){
            wrong = false;
            memset(arr,0,sizeof arr);
            j =i*input;
            if(j>98765)
                break;
            if(i<10000)
                arr[0] = 1;
            temp = i;
            while(temp>0){
                arr[temp%10]++;
                temp/=10;
            }

            temp = j;
            if(temp<10000)
                arr[0]++;
            while(temp>0){
                arr[temp%10]++;
                temp/=10;
            }
            for(int k=0;k<=9;k++)
                if(!arr[k]){
                    wrong = true;
                    break;
                }
            if(!wrong){
                found = true;
                if(j<10000) cout<<"0";
                cout<<j<<" / ";
                if(i<10000) cout<<"0";
                cout<<i<<" = "<<input<<endl;
            }
        }
        if(!found)
            cout<<"There are no solutions for "<<input<<"."<<endl;
    }
    return 0;
}
