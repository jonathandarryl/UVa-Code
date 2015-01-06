#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int term1, term2, final, attn, testcase;
    double ave, total;
    int test[3];
    cin>>testcase;
    for(int i=1;i<=testcase;i++){
        cout<<"Case "<<i<<": ";
        cin>>term1>>term2>>final>>attn;
        for(int j=0;j<3;j++)
            cin>>test[j];
        sort(test, test+3);
        ave = (test[2] + test[1])/2;
        total = term1+term2+final+attn+ave;
        if(total>=90)
            cout<<"A";
        else if(total>=80)
            cout<<"B";
        else if(total>=70)
            cout<<"C";
        else if(total>=60)
            cout<<"D";
        else
            cout<<"F";
        cout<<endl;
    }
    return 0;
}
