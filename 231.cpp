#include<iostream>
using namespace std;

int main(void){
    int catcher[100000];
    int input;
    int counter, cases;
    bool done,first = true;
    cases = 1;
    while(true){
        counter = 0;
        cin>>input;
        if(input == -1)
            break;
        catcher[0] = input;
        counter++;
        if(!first)
            cout<<endl;
        else
            first = false;
        while(true){
            cin>>input;
            if(input==-1)
                break;
            done = false;
            for(int i=0;i<counter;i++){
                if(catcher[i]<input){
                    catcher[i] = input;
                    done = true;
                    break;
                }
            }
            if(!done)
                catcher[counter++] = input;
        }
        cout<<"Test #"<<cases<<":"<<endl;
        cases++;
        cout<<"  maximum possible interceptions: "<<counter<<endl;

    }
    return 0;
}
