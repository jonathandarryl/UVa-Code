#include<stdio.h>

int main(void){
    int W, H, N, x1, x2, y1, y2, count, temp;
    int spot[500][500];
    scanf("%d %d %d", &W, &H, &N);
    while(true){
        if(W==0 && H==0 && N==0)
            break;
        for(int i=0;i<W;i++)
            for(int j=0;j<H;j++)
                spot[i][j] = 0;
        for(int i=0;i<N;i++){
            scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
            if(x1>x2){
                temp = x1;
                x1 = x2;
                x2 = temp;
            }
            if(y1>y2){
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for(int j=x1-1;j<x2;j++)
                for(int k=y1-1;k<y2;k++)
                    spot[j][k] = 1;
        }
        count = 0;
        for(int j=0;j<W;j++)
            for(int k=0;k<H;k++)
                if(spot[j][k] == 0)
                    count++;
        if(count==0) printf("There is no empty spots.\n");
        else if(count==1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n",count);
        scanf("%d %d %d", &W, &H, &N);
    }
    return 0;
}
