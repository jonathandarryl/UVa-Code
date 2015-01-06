#include<string>
#include<iostream>

using namespace std;

int main(void){
    int testcase,numX, numO;
    string tic;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        numX = numO = 0;
        for(int j=0;j<3;j++){
            cin>>tic;
            for(int k=0;k<tic.length();k++){
                if(tic.at(k) == 'X')
                    numX++;
                else if(tic.at(k) == 'O')
                    numO++;
            }
        }
        if(numX == numO || numX-1 == numO)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }


    return 0;
}
