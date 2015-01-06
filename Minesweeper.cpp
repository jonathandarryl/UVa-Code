#include<string>
#include<iostream>

using namespace std;
int main(void){
    int x,y, counter;
    int xy[102][102];
    string test;
    char bomb[102][102];
    counter = 1;
    cin>>x>>y;
    while(x!=0 && y!=0){

        if(x==y && y == 0)
            break;
        int xy[102][102] = {0};
        for(int i=1;i<=x;i++){
            cin>>test;
            for(int j=1;j<=y;j++){
                bomb[i][j] = test.at(j-1);
                if(bomb[i][j] == '*'){
                    for(int k = i-1;k<=i+1;k++)
                        for(int l = j-1;l<=j+1;l++)
                            xy[k][l]++;
                }
            }
        }
        cout<<"Field #"<<counter<<":"<<endl;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(bomb[i][j] == '*')
                    cout<<"*";
                else
                    cout<<xy[i][j];
            }
            cout<<endl;
        }
        counter++;
        cin>>x>>y;
        if(x!=0 && y!=0)
            cout<<endl;

    }
    return 0;
}
