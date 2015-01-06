#include<stdio.h>
using namespace std;

int main(void){
    int salute[] = {1,2,5,14,42,132,429,1430,4862,16796};
    int in;
    bool first = true;
    while(scanf("%d",&in)==1){
        if(!first)
            printf("\n");
        first = false;
        printf("%d\n",salute[in-1]);
    }
    return 0;
}
