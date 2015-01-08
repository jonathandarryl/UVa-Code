#include<iostream>
#include<algorithm>
using namespace std;

int main(void){

    int have, cardA, cardB;
    int max, min, countA, countB;
    while(cin>>cardA>>cardB && cardA && cardB){
        int cards[100001] = {0};
        min = 100001;
        max = 0;
        countA = countB = 0;
        for(int i=0;i<cardA;i++){
            cin>>have;
            cards[have] = 3;
            if(have>max)
                max = have;
            if(have<min)
                min = have;
        }
        for(int i=0;i<cardB;i++){
            cin>>have;
            if(have>max)
                max = have;
            if(have<min)
                min = have;
            if(cards[have]==0 || cards[have]==3)
                cards[have]+=5;
        }
        for(int i=min;i<=max;i++){
            if(cards[i]==3)
                countA++;
            else if(cards[i]==5)
                countB++;
        }
        if(countA<countB)
            cout<<countA<<endl;
        else
            cout<<countB<<endl;

    }

}
