#include<math.h>
#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int test, counter = 1;
    double u,v,a,s,t;
    while(cin>>test && test){
        if(test == 1){
            cin>>u>>v>>t;
            a = (v-u)/t;
            s = (u+v)/2*t;
            printf("Case %d: %.3lf %.3lf\n",counter,s,a);
        }
        else if(test == 2){
            cin>>u>>v>>a;
            t = (v-u)/a;
            s = (u+v)/2*t;
            printf("Case %d: %.3lf %.3lf\n",counter,s,t);
        }
        else if(test == 3){
            cin>>u>>a>>s;
            v = sqrt(pow(u,2) + 2*a*s);
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",counter,v,t);
        }
        else if(test == 4){
            cin>>v>>a>>s;
            u = sqrt(pow(v,2)-2*a*s);
            t = (v-u)/a;
            printf("Case %d: %.3lf %.3lf\n",counter,u,t);
        }
        counter++;
    }

    return 0;
}

