#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int test;
    int salary[3];

    cin>>test;
    for(int i=1;i<=test;i++){
        cout<<"Case "<<i<<": ";
        for(int j=0;j<3;j++)
            cin>>salary[j];
        sort(salary,salary+3);
        cout<<salary[1]<<endl;
    }
    return 0;
}
