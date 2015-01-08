#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

typedef struct{
    int id;
    int probsolved;
    int penalty;
    int problem[11];
    bool done[11];
}contestant_t;

contestant_t contestant[101];

void init(int index){
    contestant[index].probsolved = contestant[index].penalty = 0;
    for(int i=0;i<11;i++){
        contestant[index].problem[i] = 0;
        contestant[index].done[i] = false;
    }
}

bool sort_cmp(contestant_t a, contestant_t b){
    if(a.probsolved!=b.probsolved)
        return a.probsolved>b.probsolved;
    if(a.penalty!=b.penalty)
        return a.penalty<b.penalty;
    return a.id<b.id;

}

int main(void){
    int test,id,prob,time;
    char verdict;
    scanf("%d",&test);
    string input;
    getline(cin,input);
    getline(cin,input);
    map<int,int> mapper;
    int counter;
    while(test--){
        counter = 0;
        mapper.clear();
        while(getline(cin,input)){
            if(input.empty())
                break;
            stringstream(input)>>id>>prob>>time>>verdict;
            if(mapper.find(id)==mapper.end()){
                mapper[id]=counter++;
                init(mapper[id]);
                contestant[mapper[id]].id = id;
            }
            switch(verdict){
                case 'C':{
                    if(!contestant[mapper[id]].done[prob]){
                        contestant[mapper[id]].probsolved++;
                        contestant[mapper[id]].penalty+=time+contestant[mapper[id]].problem[prob]*20;
                        contestant[mapper[id]].done[prob] = true;
                    }
                    break;
                }
                case 'I':{
                    contestant[mapper[id]].problem[prob]++;
                    break;
                }

            }
          //  for(int i=0;i<counter;i++){
            //    printf("%d %d %d\n",contestant[i].id,contestant[i].probsolved,contestant[i].penalty);
            //}
        }
        sort(contestant,contestant+counter,sort_cmp);
        for(int i=0;i<counter;i++){
            printf("%d %d %d\n",contestant[i].id,contestant[i].probsolved,contestant[i].penalty);
        }
        if(test)
            printf("\n");
    }
    return 0;
}
