#include<iostream>
using namespace std;

int main(void){
    int n;
    while(cin>>n && n){
        int mtx[100][100];
        int row[100] = {0};
        int col[100] = {0};
        int countrow, countcol, remembercol, rememberrow;
        bool corrupt;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cin>>mtx[i][j];
        }
        corrupt = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row[i]+=mtx[i][j];
                col[j]+=mtx[i][j];
            }
            row[i] = row[i]%2;
        }

        countrow = countcol = 0;
        for(int i=0;i<n;i++)
            col[i] = col[i]%2;
        for(int i=0;i<n;i++){
            if(col[i]==1){
                countcol++;
                remembercol = i;
            }
            if(row[i]==1){
                countrow++;
                rememberrow = i;
            }
            if(countcol>1 || countrow>1){
                corrupt = true;
                break;
            }
        }
        if(countcol == 0 && countrow == 0)
            cout<<"OK"<<endl;
        if(corrupt || (countcol == 1 && countrow == 0) || (countcol == 0 && countrow == 1))
            cout<<"Corrupt"<<endl;
        else if(countcol == 1 && countrow == 1)
            cout<<"Change bit ("<<rememberrow+1<<","<<remembercol+1<<")"<<endl;



    }
    return 0;
}
