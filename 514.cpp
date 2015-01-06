#include<stack>
#include<iostream>
using namespace std;

int main(void){
    int numtrain, desired[1002],now[1002];
    int pointernow, pointerdesired;
    bool found;
    stack<int> train;
    while(cin>>numtrain && numtrain){
        while(cin>>desired[0] && desired[0]){
            found = false;
            now[0] = 1;
            for(int i=1;i<numtrain;i++){
                cin>>desired[i];
                now[i]=i+1;
            }
            pointerdesired = pointernow = 0;
            while(pointerdesired<numtrain){
                //cout<<"PTRDESIRED "<<pointerdesired<<" PTRNOW "<<pointernow<<" SIZE STACK "<<train.size()<<endl;
                if(!train.empty() && desired[pointerdesired]==train.top()){
                    train.pop();
                    pointerdesired++;
                    if(pointerdesired == numtrain){
                        found = true;
                        break;
                    }

                }
                else if(pointernow == numtrain)
                    break;
                else if(pointernow<numtrain){
                    if(desired[pointerdesired]==now[pointernow]){
                        pointernow++;
                        pointerdesired++;
                        if(pointerdesired == numtrain){
                            found = true;
                            break;
                        }
                    }
                    else{
                        train.push(now[pointernow]);
                        pointernow++;
                    }
                }
            }
            if(found)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            while(!train.empty())
                train.pop();
        }
        cout<<endl;

        }
}
