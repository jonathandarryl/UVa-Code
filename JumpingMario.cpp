#include<iostream>

using namespace std;

int main(void){
    int testcase,numofwall, high, low;
    int wall[50];
    cin>>testcase;
    for(int i=1;i<=testcase;i++){
        cout<<"Case "<<i<<":";
        cin>>numofwall;
        cin>>wall[0];
        high = 0;
        low = 0;
        for(int j=1;j<numofwall;j++){
            cin>>wall[j];
            if(wall[j-1]<wall[j])
                high++;
            else if(wall[j-1]>wall[j])
                low++;
        }
        cout<<" "<<high<<" "<<low<<endl;

    }
    return 0;
    }
