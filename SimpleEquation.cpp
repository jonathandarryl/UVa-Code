#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int test,A,B,C;
    int arr[3];
    cin>>test;
    bool found;
    for(int i=0;i<test;i++){
        cin>>A>>B>>C;
        found = false;
        for(int j=0;j<100;j++){
            if(j*j*j>B || j*j+j*j+j*j>C)
                break;
            for(int k=j+1;k<100;k++){
                if(j*k*k>B || j*j+k*k+k*k>C)
                    break;
                for(int l=k+1;l<100;l++){
                    if(j*k*l==B && j*j+k*k+l*l==C){
                        if(j+k+l==A){
                            found = true;
                            cout<<j<<" "<<k<<" "<<l<<endl;
                        }
                        else if(-j-k+l==A){
                            found = true;
                            arr[0]=-j;
                            arr[1]=-k;
                            arr[2]=l;
                            sort(arr,arr+3);
                            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
                        }
                        else if(-j+k-l==A){
                            found = true;
                            arr[0]=-j;
                            arr[1]=k;
                            arr[2]=-l;
                            sort(arr,arr+3);
                            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
                        }
                        else if(j-k-l==A){
                            found = true;
                            arr[0]=j;
                            arr[1]=-k;
                            arr[2]=-l;
                            sort(arr,arr+3);
                            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
                        }
                        break;
                    }
                    if(j*k*l>B || j*j+k*k+l*l>C)
                        break;
                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        if(!found)
            cout<<"No solution."<<endl;

    }
    return 0;
}
