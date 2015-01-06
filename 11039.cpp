#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void){
    int test, dummy;
    int countneg, countpos, countpos2, countneg2;
    int building, built;
    int sizepos[500000], sizeneg[500000];
    bool taken;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d",&building);
        countneg = countpos = 0;
        for(int j=0;j<building;j++){
            scanf("%d",&dummy);
            if(dummy>0)
                sizepos[countpos++] = dummy;
            else
                sizeneg[countneg++] = (dummy*-1);
        }
        if(building == 0)
            printf("0\n");
        else if(countneg == 0 || countpos == 0)
            printf("1\n");
        else{
            built = countpos2 = countneg2 = 0;
            sort(sizepos,sizepos+countpos);
            sort(sizeneg,sizeneg+countneg);
            if(sizepos[countpos2]<sizeneg[countneg2]){
                countpos2++;
                taken = true;
            }
            else{
                countneg2++;
                taken = false;
            }
            built++;
            while(countpos2<countpos && countneg2<countneg){
                if(taken){
                    if(sizeneg[countneg2]<sizepos[countpos2])
                        countneg2++;
                    else if(sizeneg[countneg2]>sizepos[countpos2]){
                        countpos2++;
                        built++;
                        taken = false;
                    }
                }
                else{
                    if(sizepos[countpos2]<sizeneg[countneg2])
                        countpos2++;
                    else if(sizepos[countpos2]>sizeneg[countneg2]){
                        countneg2++;
                        built++;
                        taken = true;
                    }
                }
            }
            printf("%d\n",built);
        }


    }

    return 0;
}
