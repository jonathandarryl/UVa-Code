#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void){
    int arr[3];
    while(scanf("%d %d %d",&arr[0],&arr[1],&arr[2]) && arr[0] && arr[1] && arr[2]){
        sort(arr,arr+3);
        if(arr[0] == arr[1] && arr[1] == arr[2]){
            if(arr[1]==13)
                printf("*\n");
            else{
                arr[0]++;
                printf("%d %d %d\n",arr[0],arr[0],arr[0]);
            }
        }
        else if(arr[0] == arr[1] || arr[1]==arr[2]){
            if(arr[1]==13 && arr[2]==13 && arr[0]==12)
                printf("1 1 1\n");
            else if(arr[1] == 13 && arr[2]==13)
                printf("%d 13 13\n",arr[0]+1);
            else if(arr[0] == arr[1]){
                if(arr[2]==13)
                    printf("1 %d %d\n",arr[0]+1,arr[1]+1);
                else
                    printf("%d %d %d\n",arr[0],arr[1],arr[2]+1);
            }
            else if(arr[1]==arr[2]){
                if(arr[0]+1!=arr[1])
                    printf("%d %d %d\n",arr[0]+1,arr[1],arr[2]);
                else
                    printf("%d %d %d\n",arr[1],arr[2],arr[0]+2);
            }
        }
        else{
            printf("1 1 2\n");
        }
    }
    return 0;
}
