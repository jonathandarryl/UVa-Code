#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(void){
    int row, col, start,counter,rownow,colnow;
    int traversed[400][400];
    char symbol[400][400];
    while(cin>>row>>col>>start && row && col && start){
        getchar();
        for(int i=0;i<row;i++)
            gets(symbol[i]);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                traversed[i][j]=0;
        counter = 1;
        rownow = 0;
        colnow = start-1;
        while(true){
            if(rownow<0||rownow>=row||colnow<0||colnow>=col){
                //cout<<rownow<<" "<<row<<" "<<colnow<<" "<<col<<endl;
                cout<<counter-1<<" step(s) to exit"<<endl;
                break;
            }
            else if(traversed[rownow][colnow]!=0){
                cout<<traversed[rownow][colnow]-1<<" step(s) before a loop of "<<counter-traversed[rownow][colnow]<<" step(s)"<<endl;
                break;
            }
            traversed[rownow][colnow]=counter;
            counter++;
            if(symbol[rownow][colnow]=='N')
                rownow--;
            else if(symbol[rownow][colnow]=='E')
                colnow++;
            else if(symbol[rownow][colnow]=='S')
                rownow++;
            else if(symbol[rownow][colnow]=='W')
                colnow--;
        }
    }
    return 0;
}
