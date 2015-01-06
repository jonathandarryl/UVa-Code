#include<string>
#include<iostream>
using namespace std;

int main(void){
    string input;
    int test,i=0;
    cin>>test;
    getline(cin,input);
    for(int i=0;i<test;i++){
        while(getline(cin,input)){
            if(input.length()==0)
                break;
            for(int j=0;j<input.length();j++){
                switch(input.at(j)){
                    case '0':{
                        cout<<"O";
                        break;
                    }
                    case '1':{
                        cout<<"I";
                        break;
                    }
                    case '2':{
                        cout<<"Z";
                        break;
                    }
                    case '3':{
                        cout<<"E";
                        break;
                    }
                    case '4':{
                        cout<<"A";
                        break;
                    }
                    case '5':{
                        cout<<"S";
                        break;
                    }
                    case '6':{
                        cout<<"G";
                        break;
                    }
                    case '7':{
                        cout<<"T";
                        break;
                    }
                    case '8':{
                        cout<<"B";
                        break;
                    }
                    case '9':{
                        cout<<"P";
                        break;
                    }
                    default:{
                        cout<<input.at(j);
                        break;
                    }
                }
            }
            cout<<endl;
        }
        if(i!=test-1)
        cout<<endl;
    }
    return 0;
}
