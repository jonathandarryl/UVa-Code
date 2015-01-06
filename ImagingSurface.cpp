#include<string>
#include<iostream>

using namespace std;

int main(void){
    int min, numofsurface, sum;
    string surface[13];
    string dummy;
    int gap[13];
    while(true){
        cin>>numofsurface;
        if(numofsurface == 0)
            break;
        min = 26;
        sum = 0;
        getline(cin,dummy);
        for(int i=0;i<numofsurface;i++){
            getline(cin,surface[i]);
            gap[i] = 0;
            for(int j=0;j<surface[i].length();j++){
                if(surface[i].at(j) == ' ')
                    gap[i]++;
            }
            if(gap[i]<min)
                min = gap[i];
        }
        for(int i=0;i<numofsurface;i++)
            sum+= (gap[i]-min);
        cout<<sum<<endl;
    }

    return 0;
}
