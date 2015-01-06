#include<iostream>
#include<string>
using namespace std;

int main(void){
    string inputmine[10];
    int testcase, dimension;
    cin>>testcase;

    for(int i=0;i<testcase;i++){
        int bomb[12][12] = {0};
        cin>>dimension;
        for(int j=1;j<=dimension;j++){
            cin>>inputmine[j];
            for(int k=0;k<inputmine.length();k++)
                if(inputmine[j].at(k)=='*'){
                    for(int x=j-1;x<=j+1;x++)
                        for(int y=)

                }

        }


    }



    return 0;
}
