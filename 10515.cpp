#include<map>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    string m, n;
    int m1,n1;
    while(true){
        cin>>m;
        cin>>n;
        if(m=="0" && n=="0")
            return 0;
        if(n=="0")
            cout<<"1";
        else{
            m1 = m.at(m.length()-1)-'0';
            n1 = n.at(n.length()-1)-'0';
            if(n.length()>1)
                n1+=(n.at(n.length()-2)-'0')*10;
            if(m1==1 || m1 == 5 || m1 == 6 || m1 == 0)
                cout<<m1;
            else if(m1==2){
                switch(n1%4){
                    case 0: cout<<"6";break;
                    case 1: cout<<"2";break;
                    case 2: cout<<"4";break;
                    case 3: cout<<"8";break;
                }
            }
            else if(m1==3){
                switch(n1%4){
                    case 0: cout<<"1";break;
                    case 1: cout<<"3";break;
                    case 2: cout<<"9";break;
                    case 3: cout<<"7";break;
                }
            }
            else if(m1==4){
                switch(n1%2){
                    case 0: cout<<"6";break;
                    case 1: cout<<"4";break;
                }
            }
            else if(m1==7){
                switch(n1%4){
                    case 0: cout<<"1";break;
                    case 1: cout<<"7";break;
                    case 2: cout<<"9";break;
                    case 3: cout<<"3";break;
                }
            }
            else if(m1==8){
                switch(n1%4){
                    case 0: cout<<"6";break;
                    case 1: cout<<"8";break;
                    case 2: cout<<"4";break;
                    case 3: cout<<"2";break;
                }
            }
            else if(m1==9){
                switch(n1%2){
                    case 0: cout<<"1";break;
                    case 1: cout<<"9";break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
