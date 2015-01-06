#include<iostream>
#include<string>
using namespace std;

int main(void){
    int test,length, finger[11];
    bool needed[11];
    string str;
    cin>>test;
    getline(cin,str);
    for(int i=0;i<test;i++){
        getline(cin,str);
        length = str.length();
        for(int j=1;j<=10;j++){
            needed[j] = false;
            finger[j] = 0;
        }
        for(int j=0;j<length;j++){
            switch(str.at(j)){
                case 'c':{
                    needed[1] = needed[5] = needed[6] = false;

                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }
                    if(!needed[8]){
                        finger[8]++;
                        needed[8] = true;
                    }
                    if(!needed[9]){
                        finger[9]++;
                        needed[9] = true;
                    }
                    if(!needed[10]){
                        finger[10]++;
                        needed[10] = true;
                    }
                    break;
                }
                case 'd':{
                    needed[1] = needed[5] = needed[6] = needed[10] = false;
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }
                    if(!needed[8]){
                        finger[8]++;
                        needed[8] = true;
                    }
                    if(!needed[9]){
                        finger[9]++;
                        needed[9] = true;
                    }

                    break;
                }
                case 'e':{
                    needed[1] = needed[5] = needed[6] = needed[9] = needed[10] = false;
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }
                    if(!needed[8]){
                        finger[8]++;
                        needed[8] = true;
                    }

                    break;
                }
                case 'f':{
                    needed[1] = needed[5] = needed[6] = needed[8] = needed[9] = needed[10] = false;
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }

                    break;
                }
                case 'g':{
                    needed[1] = needed[5] = needed[6] = needed[7] = needed[8] = needed[9] = needed[10] = false;
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }

                    break;
                }
                case 'a':{
                    needed[1] = needed[4] = needed[5] = needed[6] = needed[7] = needed[8] = needed[9] = needed[10] = false;
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    break;
                }
                case 'b':{
                    needed[1] = needed[3] = needed[4] = needed[5] = needed[6] = needed[7] = needed[8] = needed[9] = needed[10] = false;
                     if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }

                    break;
                }
                case 'C':{
                    needed[1] = needed[2] = needed[4] = needed[5] = needed[6] = needed[7] = needed[8] = needed[9] = needed[10] = false;
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    break;
                }
                case 'D':{
                    needed[5] = needed[6] = needed[10] = false;
                    if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }
                    if(!needed[8]){
                        finger[8]++;
                        needed[8] = true;
                    }
                    if(!needed[9]){
                        finger[9]++;
                        needed[9] = true;
                    }
                    break;
                }
                case 'E':{
                    needed[5] = needed[6] = needed[9] = needed[10] = false;
                   if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }
                    if(!needed[8]){
                        finger[8]++;
                        needed[8] = true;
                    }

                    break;
                }
                case 'F':{
                    needed[5] = needed[6] = needed[8] = needed[9] = needed[10] = false;
                    if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }
                    if(!needed[7]){
                        finger[7]++;
                        needed[7] = true;
                    }


                    break;
                }
                case 'G':{
                    needed[5] = needed[6] = needed[8] = needed[7] = needed[9] = needed[10] = false;

                    if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }
                    if(!needed[4]){
                        finger[4]++;
                        needed[4] = true;
                    }


                    break;
                }
                case 'A':{
                    needed[4] = needed[5] = needed[6] = needed[8] = needed[7] = needed[9] = needed[10] = false;
                  if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }
                    if(!needed[3]){
                        finger[3]++;
                        needed[3] = true;
                    }

                    break;
                }
                case 'B':{
                    needed[3] = needed[4] = needed[5] = needed[6] = needed[8] = needed[7] = needed[9] = needed[10] = false;
                 if(!needed[1]){
                        finger[1]++;
                        needed[1] = true;
                    }
                    if(!needed[2]){
                        finger[2]++;
                        needed[2] = true;
                    }

                    break;
                }
                default: break;
            }


        }
        for(int j=1;j<10;j++)
            cout<<finger[j]<<" ";
        cout<<finger[10]<<endl;



    }
    return 0;
}
