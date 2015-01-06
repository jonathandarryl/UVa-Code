#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef struct{
    int users;
    string name;
}source;

bool sort_comp(source a, source b){
    if(a.users!=b.users)
        return a.users>b.users;
    return a.name.compare(b.name)<0;
}

int main(void){
    string input,remname;
    map<string,int> developer;
    map<string,int> user;
    map<string,string> develuser;
    source open[1000];
    while(true){
        developer.clear();
        user.clear();
        getline(cin,input);
        if(input=="0")
            break;
        else{
            remname = input;
            developer[remname]=0;
        }
        while(true){
            getline(cin,input);
            if(input=="1")
                break;
            if(input.at(0)>='A' && input.at(0)<='Z'){
                remname = input;
                developer[remname]=0;
            }
            else{
                if(!user[input]){
                    user[input]=1;
                    developer[remname]++;
                    develuser[input]=remname;
                }
                else if(user[input]==1 && develuser[input]!=remname){
                    developer[develuser[input]]--;
                    user[input]=2;
                }
            }
        }
        int counter;
        counter = 0;
        for(map<string,int>::iterator it=developer.begin();it!=developer.end();it++){
            open[counter].name = it->first;
            open[counter].users = it->second;
            counter++;
        }
        sort(open,open+counter,sort_comp);
        for(int i=0;i<counter;i++)
            cout<<open[i].name<<" "<<open[i].users<<endl;


    }
    return 0;
}
