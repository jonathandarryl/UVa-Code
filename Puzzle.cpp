#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(void){
    string lines[5],command;
    int row,col,counter=0;
    bool valid,finish;
    char temp;
    while(true){
        counter++;
        for(int i=0;i<5;i++){
            getline(cin,lines[i]);
            if(lines[i].length()==1 && lines[i].at(0)=='Z')
                return 0;
            for(int j=0;j<5;j++){
                if(lines[i].at(j)==' '){
                    col = j;
                    row = i;
                }
            }
        }
        finish = false;
        valid = true;
        while(true){
            getline(cin,command);
            for(int i=0;i<command.length();i++){
                if(command.at(i)=='0'){
                    finish = true;
                    break;
                }
                switch(command.at(i)){
                    case 'A':{
                        if(valid && row>0){
                            lines[row].replace(col,1,1,lines[row-1].at(col));
                            lines[row-1].replace(col,1,1,' ');
                            row--;
                        }
                        else{
                            valid = false;
                        }
                        break;
                    }
                    case 'B':{
                        if(valid && row<4){
                            lines[row].replace(col,1,1,lines[row+1].at(col));
                            lines[row+1].replace(col,1,1,' ');
                            row++;
                        }
                        else{
                            valid = false;
                        }
                        break;
                    }
                    case 'R':{
                        if(valid && col<4){
                            lines[row].replace(col,1,1,lines[row].at(col+1));
                            lines[row].replace(col+1,1,1,' ');
                            col++;
                        }
                        else{
                            valid = false;

                        }
                        break;
                    }
                    case 'L':{
                        if(valid && col>0){
                            lines[row].replace(col,1,1,lines[row].at(col-1));
                            lines[row].replace(col-1,1,1,' ');
                            col--;
                        }
                        else
                            valid = false;
                        break;
                    }
                    default: valid = false;
                }
            }
            if(finish)
                break;
        }
        cout<<"Puzzle #"<<counter<<":"<<endl;
        if(valid){
            for(int i=0;i<5;i++){
                for(int j=0;j<4;j++){
                    cout<<lines[i].at(j)<<" ";
                }
                cout<<lines[i].at(4)<<endl;
            }
        }
        else
            cout<<"This puzzle has no final configuration."<<endl;
        cout<<endl;
    }
    return 0;
}
