#include<iostream>
using namespace std;

int main(void){
    int bin[9];
    int min;
    string mincomb;
    while(cin>>bin[0]>>bin[1]>>bin[2]>>bin[3]>>bin[4]>>bin[5]>>bin[6]>>bin[7]>>bin[8]){
        min = bin[3]+bin[6] + bin[2] + bin[8] + bin[1] + bin[4];
        mincomb = "BCG";
        if(min>(bin[3]+bin[6] + bin[2] + bin[5] + bin[1] + bin[7])){
            min = bin[3]+bin[6] + bin[2] + bin[5] + bin[1] + bin[7];
            mincomb = "BGC";
        }
        if(min>(bin[5]+bin[8] + bin[0] + bin[6] + bin[1] + bin[4])){
            min = bin[5]+bin[8] + bin[0] + bin[6] + bin[1] + bin[4];
            mincomb = "CBG";
        }
        if(min>(bin[5]+bin[8] + bin[0] + bin[3] + bin[1] + bin[7])){
            min = bin[5]+bin[8] + bin[0] + bin[3] + bin[1] + bin[7];
            mincomb = "CGB";
        }
        if(min>(bin[5]+bin[2] + bin[0] + bin[6] + bin[7] + bin[4])){
            min = bin[5]+bin[2] + bin[0] + bin[6] + bin[7] + bin[4];
            mincomb = "GBC";
        }
        if(min>(bin[2]+bin[8] + bin[0] + bin[3] + bin[7] + bin[4])){
            min = bin[2]+bin[8] + bin[0] + bin[3] + bin[7] + bin[4];
            mincomb = "GCB";
        }
        cout<<mincomb<<" "<<min<<endl;
    }
    return 0;
}
