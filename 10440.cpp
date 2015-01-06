#include<iostream>
using namespace std;

int main(void){
    int test,bolbal, timeacross, maxcarry, numcar, timenow, carcarried;
    int car[1440];
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>maxcarry>>timeacross>>numcar;
        for(int j=0;j<numcar;j++)
            cin>>car[j];
            timenow = carcarried = bolbal = 0;
            for(int j=0;j<numcar;j++){
                if(car[j]>timenow)
                    timenow=car[j];
                carcarried++;
                if(carcarried==maxcarry){
                    carcarried = 0;
                    timenow+=timeacross*2;

                }
            }
            if(numcar%maxcarry == 0){
                timenow-=timeacross;
                bolbal = numcar/maxcarry;
            }
            else
                bolbal = numcar/maxcarry+1;
        cout<<timenow<<" "<<bolbal<<endl;
    }

    return 0;
}
