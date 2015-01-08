#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
void convert(int, int, int[][5]);
int main(void){
    int digits[102][5];
    int test, input, counter;
    for(int i=0;i<5;i++)
        digits[1][i]=0;
    for(int i=1;i<=100;i++){
        test = i;
        counter = 0;
        while(test>0){
            convert((test%10)*(int)pow(10,counter),i,digits);
            test/=10;
            counter++;
        }
        for(int j=0;j<5;j++)
            digits[i+1][j] = digits[i][j];
    }
    while(true){
        cin>>input;
        if(input == 0)
            return 0;
        cout<<input<<": "<<digits[input][0]<<" i, "<<digits[input][1];
        cout<<" v, "<<digits[input][2]<<" x, "<<digits[input][3]<<" l, "<<digits[input][4]<<" c"<<endl;
    }
    return 0;
}

void convert(int num, int testnum, int digits[][5]){
    switch (num){
        case 1:
            digits[testnum][0]++;
            break;
        case 2:
            digits[testnum][0]+=2;
            break;
        case 3:
            digits[testnum][0]+=3;
            break;
        case 4:
            digits[testnum][0]++;
            digits[testnum][1]++;
            break;
        case 5:
            digits[testnum][1]++;
            break;
        case 6:
            digits[testnum][0]++;
            digits[testnum][1]++;
            break;
        case 7:
            digits[testnum][0]+=2;
            digits[testnum][1]++;
            break;
        case 8:
            digits[testnum][0]+=3;
            digits[testnum][1]++;
            break;
        case 9:
            digits[testnum][0]++;
            digits[testnum][2]++;
            break;
        case 10:
            digits[testnum][2]++;
            break;
        case 20:
            digits[testnum][2]+=2;
            break;
        case 30:
            digits[testnum][2]+=3;
            break;
        case 40:
            digits[testnum][2]++;
            digits[testnum][3]++;
            break;
        case 50:
            digits[testnum][3]++;
            break;
        case 60:
            digits[testnum][2]++;
            digits[testnum][3]++;
            break;
        case 70:
            digits[testnum][2]+=2;
            digits[testnum][3]++;
            break;
        case 80:
            digits[testnum][2]+=3;
            digits[testnum][3]++;
            break;
        case 90:
            digits[testnum][2]++;
            digits[testnum][4]++;
            break;
        case 100:
            digits[testnum][4]++;
            break;
    }
}
