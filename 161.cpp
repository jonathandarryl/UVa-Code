#include<iostream>
using namespace std;

int main(void){
    int signal[100];
    int min,i;
    while(cin>>signal[0] && signal[0]){
        i=1;
        int lights[18000] = {0};
        min = signal[0];
        while(cin>>signal[i] && signal[i]){
            if(min>signal[i])
                min = signal[i];
            i++;
        }
        while(true){
            for(int j=0;j<i;j++){
                for(int k=)

            }

        }

    }
    cin>>signal[0]>>signal[0];
}
