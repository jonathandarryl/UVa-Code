#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int main(void){
    int test,row,col,startr,startc,length,face;
    map<int,char> mapper;
    mapper[0]='N';
    mapper[1]='E';
    mapper[2]='S';
    mapper[3]='W';
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    char input[62][62];
    bool end;
    char in[1000];
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&row,&col);
        getchar();
        for(int i=0;i<row;i++)
            gets(input[i]);
        scanf("%d %d",&startr,&startc);
        end = false;
        startr--;
        startc--;
        getchar();
        face = 0;
        while(true){
            gets(in);
            length = strlen(in);
            for(int i=0;i<length;i++){
                switch(in[i]){
                    case 'Q':
                        end = true;
                        break;
                    case 'R':{
                        face++;
                        if(face==4)
                            face = 0;
                        break;
                    }
                    case 'L':{
                        face--;
                        if(face==-1)
                            face = 3;
                        break;
                    }
                    case 'F':{
                        if(input[startr+dr[face]][startc+dc[face]]!='*'){
                            startr+=dr[face];
                            startc+=dc[face];
                        }

                    }
                }
                if(end)
                    break;
            }
            if(end)
                break;
        }
        printf("%d %d %c\n",startr+1,startc+1,mapper[face]);
        if(test)
            printf("\n");
    }
    return 0;
}
