#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int main(void){
    string in;
    bool valid;
    map<string,int> insert;
    int sum, counter = 1;
    for(char i='a';i<='z';i++){
        in = i;
        insert[in]=counter++;
    }
    for(char i='a';i<='y';i++){
        for(char j=i+1;j<='z';j++){
            in = i;
            in = in + j;
            insert[in] = counter++;
        }
    }
    for(char i='a';i<='x';i++){
        for(char j=i+1;j<='y';j++){
            for(char k=j+1;k<='z';k++){
                in = i;
                in = in + j;
                in = in + k;
                insert[in] = counter++;
            }
        }
    }
    for(char i='a';i<='w';i++){
        for(char j=i+1;j<='x';j++){
            for(char k=j+1;k<='y';k++){
                for(char l=k+1;l<='z';l++){
                    in = i;
                    in = in + j;
                    in = in + k;
                    in = in + l;
                    insert[in] = counter++;
                }
            }
        }
    }
    for(char i='a';i<='v';i++){
        for(char j=i+1;j<='w';j++){
            for(char k=j+1;k<='x';k++){
                for(char l=k+1;l<='y';l++){
                    for(char m=l+1;m<='z';m++){
                        in = i;
                        in = in + j;
                        in = in + k;
                        in = in + l;
                        in = in + m;
                        insert[in] = counter++;
                    }
                }
            }
        }
    }
    while(cin>>in)
        cout<<insert[in]<<endl;
    return 0;
}
