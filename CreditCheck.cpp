#include<iostream>
#include<string>

using namespace std;

int main(void){
    int test, number[16],total;
    string input;
    cin>>test;
    for(int i=0;i<test;i++){
        total = 0;
        for(int j=0;j<4;j++){
            cin>>input;

            number[j*4] = ((int)input.at(0) - 48) * 2;
            if(number[j*4]>=0 && number[j*4]%9!=0)
                number[j*4] = number[j*4]%9;
            else if(number[j*4]==0)
                number[j*4]=0;
            else
                number[j*4] = 9;

            number[j*4+1] = ((int) input.at(2) - 48) * 2;
            if(number[j*4+1]>=0 && number[j*4+1]%9!=0)
                number[j*4+1] = number[j*4+1]%9;
            else if(number[j*4+1]==0)
                number[j*4+1]=0;
            else
                number[j*4+1] = 9;

            number[j*4 + 2] = (int) input.at(1) - 48;
            if(number[j*4+2]>=0 && number[j*4+2]%9!=0)
                number[j*4+2] = number[j*4+2]%9;
           else if(number[j*4+2]==0)
                number[j*4+2]=0;
            else
                number[j*4+2] = 9;

            number[j*4 + 3] = (int) input.at(3) - 48;
            if(number[j*4+3]>=0 && number[j*4+3]%9!=0)
                number[j*4+3] = number[j*4+3]%9;
            else if(number[j*4+3]==0)
                number[j*4+3]=0;
            else
                number[j*4+3] = 9;
        }
        for(int j=0;j<16;j++){
            total+=number[j];
 //           cout<<"number["<<j<<"] : "<<number[j]<<endl;
        }

        if(total%10 == 0)
            cout<<"Valid";
        else
            cout<<"Invalid";
        cout<<endl;


    }


    return 0;
}
