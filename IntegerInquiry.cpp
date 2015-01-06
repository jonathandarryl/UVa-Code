#include<iostream>
#include<string>

int main(void){
    string test[100];
    int i = 0;
    int maxdigit;
    while(true){
        cin>>test[i];
        if(test[i].length()==1 && test[i] == "0")
            break;
        if(test[i].length()>maxdigit)
            maxdigit == test[i].length();
        i++;
    }
    for(int k=maxdigit-1;k>=0;k++){
        for(int j=0;j<=i;j++){
            if(test[j].length()>k)


        }
    }

    return 0;
}
