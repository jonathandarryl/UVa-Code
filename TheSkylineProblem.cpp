#include<iostream>

using namespace std;

int main(void){
    int height[10002] = {0};
    int left, h, right,start,max;
    max = -1000;
    start = 10000;
    while(cin>>left>>h>>right){
        if(start>left)
            start = left;
        if(max<right)
            max = right;
        for(int i=left;i<right;i++){
            if(height[i] == 0)
                height[i] = h;


            else if(height[i]<h)
                height[i] = h;


        }
    }
    height[max] = 0;
    cout<<start<<" "<<height[start]<<" ";
    for(int i=start+1;i<=max;i++){
        if(height[i]!=height[i-1] && i !=max)
            cout<<i<<" "<<height[i]<<" ";
        else if(i==max)
            cout<<i<<" "<<height[i];
    }
    cout<<endl;

    return 0;
}
