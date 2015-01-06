#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(void){
    int input,counter;
    string in;
    counter = 1;
    while(scanf("%d",&input) && input){
        printf("Case %d:\n",counter++);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
        for(int i=0;i<input;i++){
            getline(cin,in);
            if(in.empty())
                i--;
            else{
                printf("printf(\"");
                for(int j=0;j<in.length();j++){
                    if(in.at(j)=='\\' || in.at(j)=='\"')
                        printf("\\");
                    printf("%c",in.at(j));
                }
                printf("\\n\");\n");
            }
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }
    return 0;
}
