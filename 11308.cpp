#include<iostream>
#include<string.h>
#include<map>
#include<stdio.h>

using namespace std;

int main(void){
    char recipe[1000];
    int printed;
    map<string,int> made;
    string input,remember,used,rem2;
    int p,ing,quan,min;
    map<string, int> menu;
    int total, test,price,cake,budget;
    cin>>test;
    for(int i=0;i<test;i++){
        getchar();
        made.clear();
        gets(recipe);
        for(int j=0;j<strlen(recipe);j++)
            cout<<(char)toupper(recipe[j]);
        cout<<endl;
        cin>>price>>cake>>budget;
        menu.clear();
        for(int j=0;j<price;j++){
            cin>>input>>p;
            menu[input]=p;
        }
        printed = 0;
        for(int j=0;j<cake;j++){
            getchar();
            getline(cin,remember);
            cin>>ing;
            total = 0;

            for(int k=0;k<ing;k++){
                cin>>used>>quan;
                total+=menu[used]*quan;
            }
            if(total<=budget){
                printed++;
                made[remember]=total;
            }

        }
        if(!printed)
            cout<<"Too expensive!"<<endl;
        else
            for(int k=0;k<printed;k++){
                min = budget+1;
                for(map<string,int>::iterator it=made.begin();it!=made.end();it++){
                    if(min>it->second){
                        min = it->second;
                        rem2 = it->first;
                    }
                }
                cout<<rem2<<endl;
                made[rem2]=1000000;
            }
        cout<<endl;
    }
    return 0;
}
