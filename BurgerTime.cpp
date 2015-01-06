#include<iostream>
#include<string>
using namespace std;

int main(void){
    string burger;
    int length,distr, distd,min;
    bool r,d;
    while(cin>>length && length){
        cin>>burger;
        r = d = false;
        min = 20000000;
        for(int i=0;i<length;i++){
            if(burger.at(i)=='Z'){
                min = 0;
                break;
            }
            if(burger.at(i)=='R'){
                if(!r){
                    r = true;
                    distr = 0;
                }
                else if(r){
                    distr = 0;
                }
                if(d){
                    distd++;
                    if(min>distd)
                        min = distd;
                    d = false;
                }

            }
            else if(burger.at(i)=='D'){
                if(!d){
                    d = true;
                    distd = 0;
                }
                else if(d){
                    distd = 0;
                }
                if(r){
                    distr++;
                    if(min>distr)
                        min = distr;
                    r = false;
                }

            }
            else if(burger.at(i)=='.'){
                if(r)
                    distr++;
                if(d)
                    distd++;

            }
        }
        cout<<min<<endl;
    }
    return 0;
}
