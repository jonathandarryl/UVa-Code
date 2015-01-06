#include<stack>
#include<queue>
#include<iostream>
using namespace std;

int main(void){
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    bool isStack, isQueue, isPQ;
    int command, pushpop, num, sum;
    while(cin>>command){
        isStack = isQueue = isPQ = true;
        for(int i=0;i<command;i++){
            cin>>pushpop>>num;
            if(pushpop == 1){
                if(isStack)
                    st.push(num);
                if(isQueue)
                    q.push(num);
                if(isPQ)
                    pq.push(num);
            }
            else if(pushpop == 2){
                if(isStack){
                    if(!st.empty() && num == st.top())
                        st.pop();
                    else
                        isStack = false;
                }
                if(isQueue){
                    if(!q.empty() && num == q.front())
                        q.pop();
                    else
                        isQueue = false;
                }
                if(isPQ){
                    if(!pq.empty() && num == pq.top())
                        pq.pop();
                    else
                        isPQ = false;
                }
            }
        }
        while(!st.empty())
            st.pop();
        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();
        sum = 0;
        if(isStack) sum++;
        if(isQueue) sum++;
        if(isPQ)    sum++;
        if(sum==0)
            cout<<"impossible";
        else if(sum>1)
            cout<<"not sure";
        else if(sum == 1){
            if(isStack)
                cout<<"stack";
            else if(isQueue)
                cout<<"queue";
            else if(isPQ)
                cout<<"priority queue";
        }
        cout<<endl;
    }
    return 0;
}
