#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    string input;
    char rem;
    int in1, in2, res;
    int track, right = 0;
    while(cin>>input){
        track = in1 = in2 = res = 0;

        while(input.at(track)>='0' && input.at(track)<='9'){
            in1*=10;
            in1+=input.at(track) -'0';
            track++;
        }
        rem = input.at(track);
        track++;
        while(input.at(track)>='0' && input.at(track)<='9'){
            in2*=10;
            in2+=input.at(track) -'0';
            track++;
        }
        track++;
        for(int i=track;i<input.length();i++){
            if(input.at(track)=='?')
                res = -10000000l;
            else{
                res*=10;
                res+=input.at(i)-'0';
            }
        }
        if(rem=='+')
            in1+=in2;
        if(rem=='-')
            in1-=in2;
        if(in1==res)
            right++;
    }
    cout<<right<<endl;
    return 0;
}
