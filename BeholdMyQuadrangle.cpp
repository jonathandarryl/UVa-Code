#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int test;
    int array[4];
    cin>>test;
    for(int i=0;i<test;i++){
        for(int j=0;j<4;j++)
            cin>>array[j];
        sort(array,array+4);
        if(array[0] == array[1] && array[1] == array[2] && array[2]==array[3] && array[3]==array[0])
            cout<<"square";
        else if(array[0]==array[1] && array[2]==array[3])
            cout<<"rectangle";
        else if(array[3] >= array[0] + array[1] + array[2])
            cout<<"banana";
        else
            cout<<"quadrangle";
        cout<<endl;
    }

    return 0;
}
