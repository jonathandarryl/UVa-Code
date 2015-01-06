#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int test,squarestring;
    string teststring;
    cin>>test;
    getline(cin,teststring);
    for(int i=0;i<test;i++){
        getline(cin,teststring);
        if(sqrt(teststring.length())!=(int) sqrt(teststring.length()))
            cout<<"INVALID"<<endl;
        else{
            squarestring = sqrt(teststring.length());
            for(int j=0;j<squarestring;j++){
                for(int k=j;k<teststring.length();k+=squarestring)
                    cout<<teststring.at(k);

            }
            cout<<endl;

        }
    }

    return 0;
}
