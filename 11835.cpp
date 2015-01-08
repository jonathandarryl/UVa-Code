#include<iostream>
using namespace std;

int main(void){
    int score[101][101];

    int match, player, scoring, max, top;
    bool first;
    while(cin>>match>>player && match && player){
        for(int i=0;i<match;i++){
            for(int j=1;j<=player;j++){
                cin>>score[i][j];
            }
        }
        cin>>scoring;

        for(int i=0;i<scoring;i++){
            max = 0;
            int scoresystem[101] = {0};
            int total[101] = {0};
            first = true;
            cin>>top;
            for(int j=1;j<=top;j++)
                cin>>scoresystem[j];
            for(int j=1;j<=player;j++){
                for(int k=0;k<match;k++)
                    total[j]+=scoresystem[score[k][j]];
                    if(total[j]>max)
                        max = total[j];
            }
            for(int j=1;j<=player;j++)
                if(total[j]==max){
                    if(first){
                        cout<<j;
                        first = false;
                    }
                    else
                        cout<<" "<<j;
                }
            cout<<endl;
        }




    }
    return 0;
}
