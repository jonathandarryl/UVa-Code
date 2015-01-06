#include<iostream>
#include<string>
using namespace std;

int main(void){
    string input;
    int row, col, important, notimportant, test;
    int max;
    int counter;
    cin>>test;
    for(int i=1;i<=test;i++){
        max = counter = 0;
        cin>>row>>col>>important>>notimportant;
        int value[26] = {0};
        for(int j=0;j<row;j++){
            cin>>input;
            for(int k=0;k<col;k++){
                value[(int)input.at(k) - 'A']++;
                if(value[(int)input.at(k) - 'A']>max)
                    max = value[(int)input.at(k) - 'A'];
            }
        }
        for(int j=0;j<26;j++){
            if(value[j]==max)
                counter+=important*value[j];
            else if(value[j]>=1)
                counter+=notimportant*value[j];
        }
        cout<<"Case "<<i<<": "<<counter<<endl;


    }


    return 0;
}
