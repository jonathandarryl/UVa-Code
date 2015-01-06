#include<iostream>
using namespace std;
unsigned int rev(unsigned int);
bool palindrome(unsigned int);

int main(void){
    unsigned int number, reversed, temp;
    int test, counter;
    cin>>test;
    for(int i=0;i<test;i++){
        cin>>number;
        counter = 0;
        while(true){
            if(palindrome(number)){
                cout<<counter<<" "<<number<<endl;
                break;
            }
            else{
                reversed = rev(number);
                number+=reversed;
                counter++;
            }
        }

    }

}

bool palindrome(unsigned int number){
    unsigned int number2 = 0,temp;
    temp = number;
    while(number>0){
        number2 = number2*10 + number%10;
        number/=10;
    }
    if(number2==temp)
        return true;
    else
        return false;
}

unsigned int rev(unsigned int number){
    unsigned int reverse = 0;
    while(number>0){
        reverse = reverse*10 + number%10;
        number/=10;
    }
    return reverse;
}
