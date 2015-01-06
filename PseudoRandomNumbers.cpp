#include<iostream>
#include<map>
using namespace std;

int main(void){
    long long first, counter, casecounter;
    long long z,i,m,l;
    map<int, int> aftermod;
    casecounter = 1;
    while(cin>>z>>i>>m>>l && (z||m||i||l)){
        aftermod.clear();
        counter = 1;
        aftermod[l]=counter++;
        while(true){
            l = z*l+i;
            l=l%m;
            if(!aftermod[l]) aftermod[l] = counter++;
            else    break;
        }
        cout<<"Case "<<casecounter<<": "<<counter-aftermod[l]<<endl;
        casecounter++;
    }
    return 0;
}
