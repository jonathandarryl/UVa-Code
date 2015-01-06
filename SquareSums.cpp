#include<iostream>
using namespace std;

int main(void){
    int num[11][11];
    int input,counter,count,casec=1;
    long long sum;
    while(cin>>input&&input){
        for(int i=0;i<input;i++)
            for(int j=0;j<input;j++)
                cin>>num[i][j];
        cout<<"Case "<<casec<<": ";
        if(input==1)
            cout<<num[0][0]<<endl;
        else{
            counter = (input+1)/2;
            count = 0;
            while(counter--){
                sum = 0;
                for(int i=count;i<input-count;i++)
                    sum+=num[count][i]+num[input-count-1][i];
                for(int i=count+1;i<input-count-1;i++)
                    sum+=num[i][count]+num[i][input-count-1];
                if(counter==0 && input%2==1)
                    sum/=2;
                cout<<sum<<" ";
                count++;
            }
            cout<<endl;
        }
    }
    return 0;
}
