#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    int n,testcase;
    double result;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>n;
        result = 0;
        for(int j=1;j<=n;j++)
            result+= log10((double) j);
        cout<<(int)floor(result+1)<<endl;

    }
    return 0;
}
