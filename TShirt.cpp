#include<iostream>
#include<string.h>
#include<map>
#include<stdio.h>
using namespace std;
string T[30][2];
int sizes,vol;
bool finish;

void trycomb(int now, map<string,int> avail){
    if(now==vol)
        finish = true;
    else{
        for(int i=0;i<2;i++){
            if(finish)
                return;
            if(avail[T[now][i]]>0){
                avail[T[now][i]]--;
                trycomb(now+1,avail);
                avail[T[now][i]]++;
            }
        }
    }
}

int main(void){
    int test, maxshirt;
    string size;
    map<string, int> avail;
    scanf("%d",&test);
    for(int i=0;i<test;i++){
        scanf("%d %d",&sizes,&vol);
        maxshirt = sizes/6;
        avail.clear();
        avail["S"]=maxshirt;
        avail["XS"]=maxshirt;
        avail["M"]=maxshirt;
        avail["L"]=maxshirt;
        avail["XL"]=maxshirt;
        avail["XXL"]=maxshirt;
        for(int j=0;j<vol;j++){
            cin>>T[j][0]>>T[j][1];
        }
        finish = false;
        trycomb(0,avail);
        if(finish)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
