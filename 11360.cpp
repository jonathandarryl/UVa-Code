#include<iostream>
#include<string>
using namespace std;

int main(void){
    int test,dimension,manipulation, a, b;
    char temptrans;
    bool swapped[10][10];
    string matrices[10], command, temp;
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>dimension;
         for(int l=0;l<dimension;l++)
            for(int k=0;k<dimension;k++)
                swapped[l][k] = false;
        for(int j=0;j<dimension;j++)
            cin>>matrices[j];
        cin>>manipulation;
        for(int j=0;j<manipulation;j++){

            cin>>command;
            if(command == "row"){
                cin>>a>>b;
                a--;
                b--;
                matrices[a].swap(matrices[b]);
            }
            else if(command == "col"){
                cin>>a>>b;
                a--;
                b--;

                for(int k=0;k<dimension;k++){
                    temptrans = matrices[k].at(a);
                    matrices[k].replace(a,1,1,matrices[k].at(b));
                    matrices[k].replace(b,1,1,temptrans);
                }
            }
            else if(command == "inc"){
                for(int k=0;k<dimension;k++){
                    for(int l=0;l<dimension;l++){
                        if(matrices[k].at(l)=='9')
                            matrices[k].replace(l,1,1,'0');
                        else
                            matrices[k].at(l)++;
                    }
                }
            }
            else if(command == "dec"){
                for(int k=0;k<dimension;k++){
                    for(int l=0;l<dimension;l++){
                        if(matrices[k].at(l)=='0')
                            matrices[k].replace(l,1,1,'9');
                        else
                            matrices[k].at(l)--;
                    }
                }
            }
            else if(command == "transpose"){
                for(int k=0;k<dimension;k++){
                    for(int l=0;l<dimension;l++){
                        if(!swapped[k][l]){
                        temptrans = matrices[k].at(l);
                        matrices[k].replace(l,1,1,matrices[l].at(k));
                        matrices[l].replace(k,1,1,temptrans);
                        swapped[k][l] = swapped[l][k] = true;
                        }
                    }
                }
                for(int l=0;l<dimension;l++)
                    for(int k=0;k<dimension;k++)
                        swapped[l][k] = false;
            }
        }
        cout<<"Case #"<<i<<endl;
        for(int z=0;z<dimension;z++){
            cout<<matrices[z]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
