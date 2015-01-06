#include<iostream>

using namespace std;

int main(void){
    int x,y,x1,y1,testcase;
    while(true){
        cin>>testcase;
        if(testcase == 0)
            break;
        cin>>x>>y;
        for(int i=0;i<testcase;i++){
            cin>>x1>>y1;
            if(x1==x || y1==y)
                cout<<"divisa";
            else if(x1<x){
                if(y1<y)
                    cout<<"SO";
                else
                    cout<<"NO";
            }
            else{
                if(y1<y)
                    cout<<"SE";
                else
                    cout<<"NE";
            }
            cout<<endl;
        }
    }
    return 0;
}
