#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<vector<int>,int> result;

long long t,n;
int arr[1000];
typedef vector<int> vectorint;
typedef vector<vectorint> vi;

void comb(vector<int> v,int now, long long sum){
    if(sum>t){
        return;
    }
    if(sum==t){
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        result[v]++;
    }
    if(now == n)
        return;
    for(int i=now;i<n;i++){
        v.push_back(arr[i]);
        comb(v,i+1,sum+arr[i]);
        v.pop_back();
    }

}

bool sort_cmp(vector<int> a, vector<int> b){
    int mini;
    if(a.size()<b.size())
        mini = a.size();
    else
        mini = b.size();
    for(int i=0;i<mini;i++){
        if(a[i]!=b[i])
            return a[i]>b[i];
    }
    return mini == a.size();
}

int main(void){
    vi res;
    vector<int> v;
    while(scanf("%d %d",&t,&n) && n){
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        result.clear();
        comb(v,0,0);
        printf("Sum of %d:\n",t);
        if(result.size()==0)
            printf("NONE\n");
        else{
            res.clear();
            for(map<vector<int>,int>::iterator it = result.begin();it!=result.end();it++){
                res.push_back(it->first);
            }
            sort(res.begin(),res.end(),sort_cmp);
            for(int i=0;i<res.size();i++){
                printf("%d",res[i][0]);
                for(int j=1;j<res[i].size();j++)
                    printf("+%d",res[i][j]);
                printf("\n");
            }

        }
    }
    return 0;
}
