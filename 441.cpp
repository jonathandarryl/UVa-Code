#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int size;
    int input[15];
    bool first = true;
    while(cin>>size && size){
        if(first)
            first = false;
        else
            printf("\n");
        for(int i=0;i<size;i++)
            cin>>input[i];
        sort(input,input+size);
        for(int i=0;i<size-5;i++)
            for(int j=i+1;j<size-4;j++)
                for(int k=j+1;k<size-3;k++)
                    for(int l=k+1;l<size-2;l++)
                        for(int m=l+1;m<size-1;m++)
                            for(int n=m+1;n<size;n++)
                                printf("%d %d %d %d %d %d\n",input[i],input[j],input[k],input[l],input[m],input[n]);
    }
    return 0;
}
