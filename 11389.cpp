#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int n,r,d, total, count;
    int morn[100];
    int noon[100];
    while(cin>>n>>d>>r && n && r && d){
        for(int i=0;i<n;i++){
            cin>>morn[i];
        }
        for(int i=0;i<n;i++){
            cin>>noon[i];
        }
        sort(morn,morn+n);
        sort(noon,noon+n);
        total = 0;
        for(int i=0;i<n;i++){
            count = morn[i] + noon[n-i-1];
            if(count>d){
                total += (count - d)*r;
            }
        }
        cout<<total<<endl;
    }

    return 0;
}
