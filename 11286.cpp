#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(void){
    int temp[5];
    map<vector<int>,int> fav;
    int input, max, num,test;

    while(cin>>input){
        max = 0;
        vector<int> v;
        if(!input)
            return 0;
        else{
            fav.clear();
            for(int i=0;i<input;i++){
                v.clear();
                for(int j=0;j<5;j++){
                    cin>>test;
                    v.push_back(test);
                }
                sort(v.begin(),v.end());
                fav[v]++;
                if(fav[v]>max)
                    max = fav[v];
            }
            num = 0;
            for(map<vector<int>,int>::iterator it = fav.begin();it!=fav.end();it++)
                if(max==it->second)
                    num+=max;
            cout<<num<<endl;
        }
    }
    return 0;
}
