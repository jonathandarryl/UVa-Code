#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(void){
    int input;
    bool found;
    int test,a;
    scanf("%d",&input);
    for(int i=0;i<input;i++){
        found = false;
        scanf("%d",&test);
        if(test%8!=7){
            a = sqrt(test);
            for(int j=0;j<=a;j++){
                for(int k=j;k<=a;k++){
                    for(int l=k;l<=a;l++){
                        if(j*j + k*k + l*l == test){
                            printf("%d %d %d\n",j,k,l);
                            found = true;
                            break;
                        }
                    }
                    if(found)
                        break;
                }
                if(found)
                    break;
            }
        }
        if(!found)
            printf("-1\n");
    }

}
