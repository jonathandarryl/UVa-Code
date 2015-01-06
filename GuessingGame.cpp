#include<iostream>
#include<string>

using namespace std;
int main(void){
    int input, indicator[11];
    bool honest, done;
    string response;
    while(true){
        honest = true;
        done = false;
        for(int i=1;i<11;i++)
            indicator[i] = 0;
        while(true){
            cin>>input;
            if(input == 0)
                return 0;
            getline(cin,response);
            getline(cin,response);
            if(response == "too high"){
                if(indicator[input] == 0 || indicator[input] == 1)
                    indicator[input] = 1;
                else
                    honest = false;
            }
            else if(response == "too low"){
                if(indicator[input] == 0 || indicator[input] == -1)
                    indicator[input] = -1;
                else
                    honest = false;
            }
            else if(response == "right on"){
                for(int i=0;i<=input;i++){
                    if(indicator[i]==1)
                        honest = false;
                }
                for(int i=input;i<=10;i++){
                    if(indicator[i]==-1)
                        honest = false;
                }
                if(honest)
                    cout<<"Stan may be honest"<<endl;
                else
                    cout<<"Stan is dishonest"<<endl;
                done = true;
            }
            if(done)
                break;
        }
    }


    return 0;
}
