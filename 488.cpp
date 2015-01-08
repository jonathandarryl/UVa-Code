#include<iostream>

using namespace std;

int main(void){

    int test, freq, amp;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>amp>>freq;
        for(int j=0;j<freq;j++){
            for(int k=1;k<=amp;k++){
                for(int l=1;l<=k;l++){
                    cout<<k;
                }
                cout<<endl;
            }
            for(int k=amp-1;k>=1;k--){
                for(int l=k;l>0;l--)
                    cout<<k;
                cout<<endl;
            }
            if(i==test-1 && j==freq-1)
                continue;
            cout<<endl;
        }
    }
    return 0;
}
