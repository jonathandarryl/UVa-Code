#include<string>
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    string number,result, str;
    int base1, base2, converted, temp;
    while(cin>>number>>base1>>base2){
        converted = 0;
        for(int i=number.length()-1;i>=0;i--){
            if((int)number.at(i)<58)
                converted+=((int)number.at(i) - 48)*pow((double)base1,number.length()-1-i);
            else
                converted+=((int)number.at(i) - 55) * pow((double)base1,number.length()-1-i);
        }
        if(converted == 0)
            result.insert(0,"0");
        while(converted>0){
            temp=converted%base2;
            converted/=base2;
            if(temp<10){
                str = (char) temp+48;
            }
            else{
                str = (char) temp+55;
            }
            result.insert(0,str);

        }
        if(result.length()>7)
            printf("  ERROR\n");
        else{
            for(int i=0;i<7-result.length();i++)
                printf(" ");
            cout<<result<<endl;
        }
        result.clear();
    }
    return 0;
}
