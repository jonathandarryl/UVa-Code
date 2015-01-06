#include<iostream>
using namespace std;

int main(void){
    int row[10000], col[10000];
    int rowA, colA, R,C,participant, poss, counter = 1;
    while(cin>>R>>C>>participant && R && C && participant){
        for(int i=0;i<R;i++)
            row[i] = 0;
        for(int i=0;i<C;i++)
            col[i] = 0;
        for(int i=0;i<participant;i++){
            cin>>rowA>>colA;
            row[rowA] = 1;
            col[colA] = 1;
        }
        poss = 0;
        cin>>rowA>>colA;
        if(row[rowA] == 0 && col[colA] == 0)
            poss++;
        else if(rowA!=0 && row[rowA-1] == 0 && col[colA]==0)
            poss++;
        else if(rowA!=R-1 && row[rowA+1] == 0 && col[colA]==0)
            poss++;
        else if(colA!=0 && row[rowA] == 0 && col[colA-1]==0)
            poss++;
        else if(colA!=C-1 && row[rowA] == 0 && col[colA+1]==0)
            poss++;
        cout<<"Case "<<counter<<": ";
        if(poss){
            cout<<"Escaped again! More 2D grid problems!"<<endl;
        }
        else
            cout<<"Party time! Let's find a restaurant!"<<endl;
        counter++;

    }
    return 0;
}
