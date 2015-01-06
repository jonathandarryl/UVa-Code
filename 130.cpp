#include<iostream>
using namespace std;

int main(void){
    int people[101];
    int start, count, num, counter, countdead, countadd, remember;
    bool fail;
    while(cin>>num>>count && num && count){
        start = 1;
        fail = true;
        while(fail){
            counter = start;
            countdead = 0;
            countadd = 1;
            for(int i=1;i<=num;i++)
                people[i] = 1;
            while(true){
                while(countadd<(count)){
                    if(people[counter]==1){
                        counter++;
                        countadd++;
                    }
                    else
                        counter++;
                    if(counter>num)
                        counter = 1;
                }
                if(people[counter]){
                    people[counter] = 0;

                }
                else{
                    while(!people[counter]){
                        counter++;
                        if(counter>num)
                            counter = 1;
                    }
                    people[counter] = 0;

                }
                remember = counter;
                countadd = 0;
                while(countadd<(count)){
                    if(people[counter]==1){
                        counter++;
                        countadd++;
                    }
                    else
                        counter++;
                    if(counter>num)
                        counter = 1;
                }
                if(people[counter]){
                    people[counter] = 0;

                }
                else{
                    while(!people[counter]){
                        counter++;
                        if(counter>num)
                            counter = 1;
                    }
                    people[counter] = 0;

                }
                people[remember] = 1;
                countdead++;
                //for(int i=1;i<=num;i++)
                    //cout<<" "<<people[i];
                //cout<<endl;
                if(remember == 1 && countdead<num)
                    break;
                if(remember == 1 && countdead==num){
                    fail = false;
                    break;
                }
                counter = remember;
            }
            if(fail)
                start++;
        }
        cout<<start<<endl;
    }
    return 0;
}
