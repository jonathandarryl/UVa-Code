#include<iostream>
#include<string.h>
using namespace std;
char str[27][27];
int dr[] = {1,1,0,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
int count;
int floodfill(int, int, char, char);
int main(void){
    int test;
    cin>>test;
    string input;
    int counter, max, temp;
    getline(cin,input);
    getline(cin,input);
    for(int i=0;i<test;i++){
        counter = 0;
        while(getline(cin,input)){
            if(input.empty())
                break;
            for(int j=0;j<input.length();j++)
                str[counter][j] = input.at(j);
            counter++;
        }
        count = counter;
        max = 0;
        for(int j=0;j<counter;j++){
            for(int k=0;k<counter;k++){
                if(str[j][k]=='1'){
                    temp = floodfill(j,k,'1','0');
                    if(temp>max)
                        max = temp;
                }
            }
        }
        cout<<max<<endl;
        if(i!=test-1)
            cout<<endl;
    }
    return 0;
}


int floodfill(int r, int c, char c1, char c2){
    if(r<0 || r>=count || c<0 || c>=count)
        return 0;
    if(str[r][c]!=c1)
        return 0;
    int ans = 1;
    str[r][c] = c2;
    for(int d=0;d<8;d++)
        ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
    return ans;
}
