#include<iostream>

using namespace std;

int main(void){
    int testcase;
    int height[10];
    bool consistent;
    cin>>testcase;
    cout<<"Lumberjacks:"<<endl;
    for(int i=0;i<testcase;i++){
        cin>>height[0]>>height[1];
        consistent = true;
        for(int j=2;j<=9;j++)
            cin>>height[j];
        if(height[0]>height[1]){
            for(int j=1;j<9;j++)
                if(height[j]<height[j+1]){
                    consistent = false;
                    break;
                }
        }
        else{
            for(int j=1;j<9;j++)
                if(height[j]>height[j+1]){
                    consistent = false;
                    break;
                }
        }
        if(consistent)
            cout<<"Ordered"<<endl;
        else
            cout<<"Unordered"<<endl;

    }

    return 0;
}
