#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int soldier[21];
    int N,left,right,counter, counteradd, counterleft, counterright,remember;
    while(cin>>N>>right>>left && N && left && right){
        counter = 0;
        counterleft = N;
        counterright = 1;
        for(int i=1;i<=N;i++)
            soldier[i] = 1;
        while(counter<N){
            counteradd = 0;
            while(counteradd<right){
                if(counterright>N)
                    counterright = 1;
                if(soldier[counterright]){
                    counteradd++;
                    if(counteradd == right)
                        break;
                    counterright++;
                }
                else{
                    counterright++;
                }
            }

            counteradd = 0;
            while(counteradd<left){
                //cout<<"counterleft"<<counterleft<<endl;
                if(counterleft==0)
                    counterleft = N;
                if(soldier[counterleft]){
                    counteradd++;
                    if(counteradd == left)
                        break;
                    counterleft--;
                }
                else
                    counterleft--;
            }
            soldier[counterleft] = 0;
            soldier[counterright] = 0;
            if(counterleft ==counterright){
                counter++;
                printf("%3d",counterright);
                if(counter<N)
                    cout<<",";
            }
            else{
                counter+=2;
                printf("%3d%3d",counterright,counterleft);
                if(counter<N)
                    cout<<",";
            }
        }
        cout<<endl;
    }
    return 0;
}
