#include<iostream>
#include<string>
using namespace std;

int main(void){
    string input[2];
    int month[2],date[2],year[2], age;
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){
        cout<<"Case #"<<i<<": ";
        for(int j=0;j<2;j++){
            cin>>input[j];
            date[j] = ((int)input[j].at(0) - 48)*10 + (int)input[j].at(1) - 48;
            month[j] = ((int)input[j].at(3) - 48)*10 + (int)input[j].at(4) - 48;
            year[j] = ((int)input[j].at(6) - 48)*1000 + ((int)input[j].at(7) - 48)*100 + ((int)input[j].at(8) - 48)*10 + (int)input[j].at(9) - 48;
        }
        if(year[0]<year[1] || year[0]==year[1] && month[0]<month[1] || year[0]==year[1] && month[0]==month[1] && date[0]<date[1])
            cout<<"Invalid birth date"<<endl;
        else{
            age = year[0]-year[1];
            if(month[0]<month[1])
                age--;
            else if(month[0]==month[1] && date[0]<date[1])
                age--;
            if(age>130)
                cout<<"Check birth date"<<endl;
            else
                cout<<age<<endl;

        }
    }


    return 0;
}

