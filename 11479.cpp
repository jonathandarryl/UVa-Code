#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    long long triangle[3];
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){

        for(int j=0;j<3;j++)
            cin>>triangle[j];

        cout<<"Case "<<i<<": ";
        sort(triangle,triangle+3);
        if(triangle[2]>=triangle[0]+triangle[1])
            cout<<"Invalid"<<endl;
        else if(triangle[0]<=0 || triangle[1]<=0 || triangle[2]<=0)
            cout<<"Invalid"<<endl;
        else if(triangle[0]==triangle[1]&&triangle[1]==triangle[2])
            cout<<"Equilateral"<<endl;
        else if(triangle[0]==triangle[1] || triangle[0]==triangle[2] || triangle[1] == triangle[2])
            cout<<"Isosceles"<<endl;
        else
            cout<<"Scalene"<<endl;

    }
    return 0;
}
