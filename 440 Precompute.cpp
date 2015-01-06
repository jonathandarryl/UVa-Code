#include<iostream>
using namespace std;

int main(void){
    int turn[151];
    int turnedoff, counter,tries, countadd;
    bool fail;
    int n;
    tries = 1;
    for(int n=3;n<150;n++){
            fail = false;
            for(int i=2;i<=n;i++)
                turn[i]=1;
                turn[1] = 0;
                counter = 1;
                turnedoff = 1;
            while(turnedoff<n){
                countadd = 1;
                while(countadd<tries){
                    if(turn[counter]){
                        countadd++;
                        counter++;
                    }
                    else{
                        counter++;
                    }
                    if(counter>n)
                        counter = 1;

                }
                if(turn[counter]){
                    turn[counter]=0;
                    turnedoff++;
                }
                else{
                    while(turn[counter]==0){
                        counter++;
                        if(counter>n)
                            counter=1;
                    }
                    turn[counter]=0;
                    turnedoff++;
                }
                if(counter==2 && turnedoff<n){
                    tries++;
                    n--;
                    fail=true;
                    break;
                }
            }
            if(!fail){
                cout<<n<<" "<<tries<<endl;
                tries = 1;

            }

    }


}
