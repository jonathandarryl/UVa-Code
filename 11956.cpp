#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

int main(void){
    //freopen("D:/Code/in.txt","r",stdin);
    int tc;
    int arr[100];
    int casecounter = 1;
    sc(tc);
    map<int,char> mapper;
    int now;
    char command[100010];
    mapper[0] = '0';
    mapper[1] = '1';
    mapper[2] = '2';
    mapper[3] = '3';
    mapper[4] = '4';
    mapper[5] = '5';
    mapper[6] = '6';
    mapper[7] = '7';
    mapper[8] = '8';
    mapper[9] = '9';
    mapper[10] = 'A';
    mapper[11] = 'B';
    mapper[12] = 'C';
    mapper[13] = 'D';
    mapper[14] = 'E';
    mapper[15] = 'F';
    TC(){
        now = 0;
        reset(arr,0);
        scanf("%s",command);
        int length = strlen(command);
        FOR(i,length){
            switch(command[i]){
                case '+':{
                    arr[now]++;
                    arr[now] = arr[now]%256;
                    break;
                }
                case '-':{
                    arr[now]--;
                    if(arr[now] < 0) arr[now] = 255;
                    break;
                }
                case '<':{
                    now--;
                    if(now < 0) now = 99;
                    break;
                }
                case '>':{
                    now++;
                    now = now%100;
                    break;
                }
            }
        }
        printf("Case %d:",casecounter++);
        int rem;
        FOR(i,100){
            printf(" ");
            if(arr[i] == 0)printf("00");
            else if(arr[i]<16){
                rem = arr[i]%16;
                printf("0%c",mapper[rem]);
            }
            else{
                stack<char> st;
                while(arr[i]>0){
                    rem = arr[i]%16;
                    arr[i]/=16;
                    st.push(mapper[rem]);
                }
                while(!st.empty()){
                    printf("%c",st.top());
                    st.pop();
                }
            }
        }
        printf("\n");
    }
    return 0;
}


