#include<vector>
#include<iostream>
using namespace std;
long long maximum;
void wronghat(int now, int supposed, int arr[]){
    if(now>supposed){
        maximum++;
        return;
    }
    int temp;
    for(int i=1;i<=supposed;i++)
        if(now!=i && arr[i]!=0){
            arr[i]=0;
            wronghat(now+1,supposed,arr);
            arr[i]=i;
        }
    return;

}
int main(void){
    int arr[13];
    for(int i=2;i<=12;i++){
        for(int j=1;j<=i;j++)
            arr[j]=j;
        maximum = 0;
        wronghat(1,i,arr);
        cout<<maximum<<endl;
    }

    return 0;
}
