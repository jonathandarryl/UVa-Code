#include<iostream>
#include<queue>
#include<stdio.h>
#include<map>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

bool differbyone(string a, string b){
    int c=0;
    for(int i=0;i<a.length();i++){
        if(a.at(i)!=b.at(i))
            c++;
        if(c>1)
            return false;
    }
    return c==1?true:false;
}

int main(void){
    vector<vii> AdjList;
    int test,len,counter;
    map<string, int> word;
    map<int,string> reverseWord;
    map<int,int> length;
    string input,from,to,input2;
    scanf("%d",&test);
    while(test--){
        AdjList.assign(201,vii());
        counter = 0;
        word.clear();
        reverseWord.clear();
        while(true){
            cin>>input;
            if(input=="*")
                break;
            word[input]=counter;
            reverseWord[counter] = input;
            length[counter] = input.length();
            for(int j=0;j<counter;j++){
                if(length[j] == length[counter] && differbyone(reverseWord[j], reverseWord[counter])){
                    AdjList[j].push_back(ii(counter,0));
                    AdjList[counter].push_back(ii(j,0));
                }
            }
            counter++;
        }
        getline(cin,input);
        while(getline(cin,input2)){
            if(input2.empty())
                break;
            stringstream ss;
            ss<<input2;
            ss>>from>>to;
            cout<<from<<" "<<to<<" ";
            if(from==to)
                cout<<0<<endl;
            else{
                queue<int> q;
                map<int,int> dist;
                dist[word[from]]=1;
                q.push(word[from]);
                while(!q.empty()){
                    int s = q.front();
                    q.pop();
                    for(int i=0;i<(int)AdjList[s].size();i++){
                        ii v = AdjList[s][i];
                        if(!dist[v.first]){
                            dist[v.first] = dist[s]+1;
                            q.push(v.first);
                        }
                    }
                    if(dist[word[to]])
                        break;
                }
                cout<<--dist[word[to]]<<endl;
            }
        }
        if(test)
            cout<<endl;
    }

    return 0;
}
