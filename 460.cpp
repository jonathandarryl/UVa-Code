#include<iostream>
using namespace std;

int main(void){
    int xl1,yl1,xl2,yl2,xu1,xu2,yu1,yu2;
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>xl1>>yl1>>xu1>>yu1;
        cin>>xl2>>yl2>>xu2>>yu2;
        if(xl1<xu2 && yl1<yu2 && xu2>xl1 && yu2>yl1){
            if(xl1<xl2)
                cout<<xl2;
            else
                cout<<xl1;
            cout<<" ";

            if(yl1<yl2)
                cout<<yl2;
            else
                cout<<yl1;
            cout<<" ";
            if(xu1<xu2)
                cout<<xu1;
            else
                cout<<xu2;
            cout<<" ";
            if(yu1<yu2)
                cout<<yu1;
            else
                cout<<yu2;
            cout<<endl;
        }
        else
            cout<<"No overlap"<<endl;
    }


    return 0;
}
