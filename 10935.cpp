#include<iostream>
#include<queue>
using namespace std;

int main(void){
    queue<int> deck;
    int input;
    while(cin>>input && input){
        for(int i=1;i<=input;i++){
            deck.push(i);
        }
        cout<<"Discarded cards:";
        for(int i=0;i<input-1;i++){
            cout<<" "<<deck.front();
            deck.pop();
            deck.push(deck.front());
            deck.pop();
            if(i!=input-2)
                cout<<",";
        }
        cout<<endl;
        cout<<"Remaining card: "<<deck.front()<<endl;
        deck.pop();
    }
    return 0;
}
