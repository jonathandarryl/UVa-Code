#include<iostream>
#include<string>
using namespace std;

int main(void){
    string judge[100],tobejudged[100];
    int line1, line2, counter;
    bool accepted;
    counter = 0;
    while(true){
        counter++;
        cin>>line1;
        if(line1 == 0)
            return 0;
        for(int i=0;i<line1;i++)
            getline(cin,judge[i]);
        cin>>line2;
        for(int i=0;i<line2;i++)
            getline(cin,tobejudged[i]);
        accepted = true;
        if(line1==line2){
            for(int i=0;i<line1;i++){
                if(judge[i]!=tobejudged[i]){
                    accepted = false;
                    break;
                }
            }
            if(accepted)
                cout<<"Run #"<<counter<<": Accepted"<<endl;
            else{
                for(int i=0;i<line1;i++){
                    for(int j=0;j<judge[i].length();j++){
                        if((int)judge[i].at())
                    }
                    for(int j=0;j<tobejudged[i].length();j++){

                    }
                }





            }
        }


    }

    return 0;
}

