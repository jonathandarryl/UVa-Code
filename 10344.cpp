#include<cstdio>
using namespace std;

bool valid;
int arr[5],d;
int counter = 0;
bool does(int total,int x){
    if(x==4){
        counter++;
        printf("%d\n",total);
        if(total == 23){valid = true;}
        return false;
    }

    //printf("%d %d\n",total,x);
    //scanf("%d",&d);
    does(total+arr[x+1],x+1);
    does(total-arr[x+1],x+1);
    does(total*arr[x+1],x+1);
    //return false;
}

int main(void){

    while(1){
        for(int i=0;i<5;i++)
            scanf("%d",&arr[i]);
        if(arr[0] == arr[1] && arr[1]==arr[2] && arr[2]==arr[3] && arr[3] == arr[4] && arr[0] == 0)
            break;
        valid = false;
        does(arr[0],0);
        if(valid) printf("Possible\n");
        else printf("Impossible\n");
        printf("%d\n",counter);
    }

    return 0;
}
