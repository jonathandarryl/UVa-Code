#include<string>
#include<iostream>
using namespace std;

int main(void){
    int round, falsecounter;
    string realstr, trial;
    bool isRight;
    while(true){
        cin>>round;
        if(round == -1)
            break;
        cout<<"Round "<<round<<endl;
        cin>>realstr>>trial;
        for(int i=0;i<trial.length()-1;i++){
            for(int j=i+1;j<trial.length();j++)
                if(trial.at(i)==trial.at(j)){
                    trial.erase(j,1);
                    j--;
                }
        }
        falsecounter = 0;
        for(int i=0;i<=trial.length();i++){
            if(falsecounter==7){
                cout<<"You lose."<<endl;
                break;
            }
            if(realstr.length() == 0){
                cout<<"You win."<<endl;
                break;
            }
            if(i==trial.length()){
                cout<<"You chickened out."<<endl;
                break;
            }

            isRight = false;
            for(int j=0;j<realstr.length();j++){
                if(realstr.at(j) == trial.at(i)){
                    realstr.erase(j,1);
                    j--;
                    isRight = true;
                }
            }
            if(!isRight)
                falsecounter++;
        }
    }
    return 0;
}
