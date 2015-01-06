#include<iostream>
using namespace std;

int main(void){
    int notes[10001];
    int input, peak;
    bool increase;
    while(true){
        cin>>input;
        peak = 0;
        if(input == 0)
            return 0;
        for(int i=1;i<=input;i++)
            cin>>notes[i];
        notes[input+1] = notes[1];
        notes[0] = notes[input];
        if(notes[0]>notes[1])
            increase = false;
        else
            increase = true;
        for(int i=1;i<=input;i++){
            if(notes[i]>notes[i+1]){
                if(increase){
                    peak++;
                }
                increase = false;
            }
            else{
                if(!increase)
                    peak++;
                increase = true;
            }
        }
        cout<<peak<<endl;
    }
    return 0;
}
