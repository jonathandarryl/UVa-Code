#include<cstdio>
#include<map>
using namespace std;

int main(void){
    int n;
    map<int,int>mapper;
    int arr[1000000];
    while(scanf("%d",&n) && n){
        mapper.clear();
        int a,b, counter = 0;
        for(int i=0;i<2*n;i++) arr[i] = 0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            if(mapper.find(a)==mapper.end()){
                mapper[a] = counter++;
            }
            if(mapper.find(b)==mapper.end())
                mapper[b] = counter++;
            arr[mapper[a]]--;
            arr[mapper[b]]++;
        }
        bool valid = true;
        for(int i=0;i<counter;i++)
            if(arr[i]){valid = false;break;}
        if(valid) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
