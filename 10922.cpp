#include<cstdio>
#include<cstring>
using namespace std;

int main(void){
    char arr[1010];
    while(scanf("%s",arr) && arr[0]!='0'){
        printf("%s is ",arr);
        int len = strlen(arr);
        int total = 0;
        for(int i=0;i<len;i++){
            total+=arr[i]-'0';
            //printf("%d\n",total);
        }
        if(total%9==0){
            printf("a multiple of 9 and has 9-degree ");
            int counter = 1;
            if(total==9) printf("1.\n");
            else{
                while(total!=9){
                    int temp = total;
                    int temp2 = 0;
                    while(temp>0){
                        temp2 += temp%10;
                        temp/=10;
                    }
                    counter++;
                    total = temp2;
                }
                printf("%d.\n",counter);
            }
        }
        else
            printf("not a multiple of 9.\n");
        //printf("%d\n",total);
    }

    return 0;
}
