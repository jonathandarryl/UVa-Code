#include<iostream>
using namespace std;

int main(void){
    string hortop[10] = {"-"," ","-","-"," ","-","-","-","-","-"};
    string verfronttop[10] = {"|"," "," "," ","|","|","|"," ","|","|"};
    string verbacktop[10] = {"|","|","|","|","|"," "," ","|","|","|"};
    string hormid[10] = {" "," ","-","-","-","-","-"," ","-","-"};
    string verfrontbot[10] = {"|"," ","|"," "," "," ","|"," ","|"," "};
    string verbackbot[10] = {"|","|"," ","|","|","|","|","|","|","|"};
    string horbot[10] = {"-"," ","-","-"," ","-","-"," ","-","-"};
    int dimension;
    string in;
    while(cin>>dimension>>in && dimension){
        for(int i=0;i<in.length();i++){
            cout<<" ";
            for(int j=0;j<dimension;j++)
                cout<<hortop[in.at(i)-'0'];
            cout<<" ";
            if(i!=in.length()-1)
                cout<<" ";
        }
        cout<<endl;
        for(int j=0;j<dimension;j++){
            for(int i=0;i<in.length();i++){
                cout<<verfronttop[in.at(i)-'0'];
                for(int k=0;k<dimension;k++)
                    cout<<" ";
                cout<<verbacktop[in.at(i)-'0'];
                if(i!=in.length()-1)
                    cout<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<in.length();i++){
            cout<<" ";
            for(int j=0;j<dimension;j++)
                cout<<hormid[in.at(i)-'0'];
            cout<<" ";
            if(i!=in.length()-1)
                cout<<" ";
        }
        cout<<endl;
        for(int j=0;j<dimension;j++){
            for(int i=0;i<in.length();i++){
                cout<<verfrontbot[in.at(i)-'0'];
                for(int k=0;k<dimension;k++)
                    cout<<" ";
                cout<<verbackbot[in.at(i)-'0'];
                if(i!=in.length()-1)
                    cout<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<in.length();i++){
            cout<<" ";
            for(int j=0;j<dimension;j++)
                cout<<horbot[in.at(i)-'0'];
            cout<<" ";
            if(i!=in.length()-1)
                cout<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}
