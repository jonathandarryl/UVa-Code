#include<iostream>
#include<string.h>
using namespace std;

int main(void){
    int maxrow, maxcol,row,col;
    int safe[51][51] = {0};
    cin>>maxrow>>maxcol;
    char now;
    string input;
    bool lost;
    while(cin>>row>>col>>now){
        getline(cin,input);
        getline(cin,input);
        lost = false;
        for(int i=0;i<input.length();i++){
            if(now == 'N'){
                if(input.at(i)=='R')
                    now = 'E';
                if(input.at(i)=='L')
                    now = 'W';
                if(input.at(i)=='F'){
                    if(col!=maxcol)
                        col++;
                    else if(safe[row][col] == 0){
                        lost = true;
                        safe[row][col] = 1;
                        break;
                    }
                }
            }
            else if(now == 'S'){
                if(input.at(i)=='R')
                    now = 'W';
                if(input.at(i)=='L')
                    now = 'E';
                if(input.at(i)=='F'){
                    if(col!=0)
                        col--;
                    else if(safe[row][col] == 0){
                        lost = true;
                        safe[row][col] = 1;
                        break;
                    }
                }
            }
            else if(now == 'E'){
                if(input.at(i)=='R')
                    now = 'S';
                if(input.at(i)=='L')
                    now = 'N';
                if(input.at(i)=='F'){
                    if(row!=maxrow)
                        row++;
                    else if(safe[row][col] == 0){
                        lost = true;
                        safe[row][col] = 1;
                        break;
                    }
                }
            }
            else if(now == 'W'){
                if(input.at(i)=='R')
                    now = 'N';
                if(input.at(i)=='L')
                    now = 'S';
                if(input.at(i)=='F'){
                    if(row!=0)
                        row--;
                    else if(safe[row][col] == 0){
                        lost = true;
                        safe[row][col] = 1;
                        break;
                    }
                }
            }

        }
        cout<<row<<" "<<col<<" "<<now;
        if(lost)
            cout<<" LOST";
        cout<<endl;

    }
    return 0;
}
