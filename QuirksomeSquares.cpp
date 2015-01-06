#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                for(int l=0;l<=9;l++)
                    for(int m=0;m<=9;m++)
                        for(int n=0;n<=9;n++)
                            for(int o=0;o<=9;o++)
                                for(int p=0;p<=9;p++){
                                    if(pow(i*1000+j*100 + k*10 + l + m*1000 + n*100 + o*10 + p,2)==i*10000000 +j*1000000 + k*100000 + l*10000 + m*1000 + n*100+ o*10 + p)
                                        cout<<i<<j<<k<<l<<m<<n<<o<<p<<"\\n";
                }
    return 0;

}
