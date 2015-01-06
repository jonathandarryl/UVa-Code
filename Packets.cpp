#include<iostream>
using namespace std;

int main(void){
    long long box[7],remaining;
    long long total;
    while(true){
        for(int i=1;i<7;i++)
            cin>>box[i];
        if(!box[1] && !box[2] && !box[3] && !box[4] && !box[5] && !box[6])
            return 0;
        total = box[6] + box[5] + box[4] + (box[3]+3)/4;

        box[1]-=box[5]*11;
        if(box[1]<0)
            box[1] = 0;
        box[2]-=box[4]*5;
        if(box[2]<0){
            box[1]+=box[2]*4;
            box[2] = 0;
        }
        if(box[1]<0)
            box[1] = 0;
        if(box[3]%4==1){
            box[2]-=5;
            if(box[2]<0){
                box[1]+=box[2]*4;
                box[2] = 0;
            }
            box[1]-=7;
            if(box[1]<0)
                box[1]=0;
        }
        else if(box[3]%4==2){
            box[2]-=3;
            if(box[2]<0){
                box[1]+=box[2]*4;
                box[2] = 0;
            }
            box[1]-=6;
            if(box[1]<0)
                box[1]=0;
        }
        else if(box[3]%4==3){
            box[2]-=1;
            if(box[2]<0){
                box[1]+=box[2]*4;
                box[2] = 0;
            }
            box[1]-=5;
            if(box[1]<0)
                box[1]=0;
        }
        total+=(box[2]+8)/9;
        if(box[2]%9)
            box[1]-=36-((box[2]%9)*4);
        if(box[1]<0)
            box[1]=0;
        total+=(box[1]+35)/36;
        cout<<total<<endl;
    }
    return 0;
}
