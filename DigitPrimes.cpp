#include<stdio.h>
#include<string.h>

bool sieve[1000000];
int digit[1000000];

void sieves(){
    memset(sieve,true,sizeof sieve);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<1000;i++)
        if(sieve[i])
            for(int j=i*i;j<1000000;j+=i)
                sieve[j]=false;

}
void generate(){
    digit[0]=digit[1]=0;
    int temp,num;

    for(int i=2;i<1000000;i++){
        if(sieve[i]){
            num = i;
            temp = 0;
            while(num>0){
                temp+=num%10;
                num/=10;
            }
            if(sieve[temp])
                digit[i]=digit[i-1]+1;
            else
                digit[i]=digit[i-1];
        }
        else
        digit[i]=digit[i-1];
    }
}

int main(void){
    sieves();
    generate();
    int test,low,high;
    int temp,result,num;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d %d",&low,&high);
        num = low;
        temp = 0;
        while(num>0){
            temp+=num%10;
            num/=10;
        }
        result = digit[high]-digit[low];
        if(sieve[temp] && sieve[low])
            result++;
        printf("%d\n",result);
    }
    return 0;
}
