#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef struct{
    int input;
    int mods;
}data;

bool sort_comp(data a, data b){
    if(a.mods!=b.mods)
        return a.mods<b.mods;
    else if(abs(a.input%2)!=abs(b.input%2))
        return abs(a.input%2)>abs(b.input%2);
    else if(a.input%2==0)
        return a.input<b.input;
    else
        return a.input>b.input;

}

int main(void){
    int n,m;
    data num[10001];
    while(cin>>n>>m && (n || m)){
        for(int i=0;i<n;i++){
            cin>>num[i].input;
            num[i].mods = num[i].input%m;
        }
        cout<<n<<" "<<m<<endl;
        sort(num,num+n,sort_comp);
        for(int i=0;i<n;i++){
            cout<<num[i].input<<endl;
        }
    }
    cout<<"0 0"<<endl;
    return 0;
}
