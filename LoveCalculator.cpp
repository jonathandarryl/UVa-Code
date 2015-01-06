#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(void){
    string name[2];
    int length[2],number;
    double ratio;
    int value[2];
    while(getline(cin,name[0]) && getline(cin,name[1])){
        for(int j=0;j<2;j++){
            value[j] = 0;
            length[j] = name[j].length();
            for(int i=0;i<length[j];i++){
                if((int)name[j].at(i)>=97 && (int)name[j].at(i)<=122)
                    value[j] += (int)name[j].at(i) - 96;
                else if((int)name[j].at(i)>=65 && (int)name[j].at(i)<=90)
                    value[j] += (int)name[j].at(i) - 64;
            }

            while(value[j]>9){
                number = 0;
                while(value[j]>0){
                    number+= value[j]%10;
                    value[j]/=10;
                }
                value[j] = number;
            }
        }

        if(value[0] == value[1] && value[1] == 0)
            printf("0.00 %%\n");
        else{
            if(value[0]<value[1])
                ratio = 100.0*value[0]/value[1];
            else
                ratio = 100.0*value[1]/value[0];
            printf("%.2f %%\n",ratio);
        }

    }
    return 0;
}
