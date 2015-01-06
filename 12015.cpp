#include<iostream>
#include<string>
using namespace std;


struct web{
    string nama;
    int relevance;
};

int main(void){
    int testcase, max;
    web nyoba[10];
    cin>>testcase;
    for(int i=1;i<=testcase;i++){
        max = 0;
        cout<<"Case #"<<i<<":"<<endl;
        for(int j=0;j<10;j++){
            cin>>nyoba[j].nama >>nyoba[j].relevance;
            if(max<nyoba[j].relevance)
                max = nyoba[j].relevance;
        }
        for(int j=0;j<10;j++){
            if( nyoba[j].relevance == max)
                cout<<nyoba[j].nama<<endl;
        }

    }
}

