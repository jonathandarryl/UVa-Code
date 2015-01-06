#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int n, dif;
    int jump[3000];
    int jump1[3000];
    bool isJolly;
    while(cin>>n){
        isJolly = true;
        for(int i=0;i<n;i++){
            jump[i] = 0;
            cin>>jump1[i];
        }
        for(int i=0;i<n-1;i++){
            dif = fabs((double)(jump1[i]-jump1[i+1]));
            if(dif<n)
                jump[dif] = 1;
        }
        for(int i=1;i<n;i++){
            if(jump[i]==0){
                isJolly = false;
                break;
            }
        }
        if(isJolly)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;



    }
    return 0;
}
