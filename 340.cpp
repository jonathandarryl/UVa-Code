#include <iostream>
using namespace std;

int computeSinks(int [],int [], int);
int computeHit(int [], int [], int);

int main(void)
{
    int counter, peg[1000],guess[1000];
    int test, sink, hit;
    bool playing;
    counter = 1;
    while(true){
        cin>>test;
        if(test == 0)
            return 0;
        playing = true;
        for(int i=0;i<test;i++){
            cin>>peg[i];
        }
        cout<<"Game "<<counter<<":"<<endl;
        while(playing){
            for(int i=0;i<test;i++){
                cin>>guess[i];
            }
            for(int i=0;i<test;i++){
                if(i==test-1 && guess[test-1]==0)
                    playing = false;
                if(guess[i]!=0)
                    break;
            }
            if(!playing)
                break;
            sink=computeSinks(peg, guess,test);
            hit=computeHit(peg, guess,test);
            cout<<"    ("<<sink<<","<<hit<<")"<<endl;
        }
        counter++;
    }
    return 0;
}
//To compute how many sinks that a guess has.(sink:correct number and position)
int computeSinks(int secret[], int guess[], int test)
{
    int i, sink=0;
    for(i=0;i<test;i++)
    {
        if(secret[i]==guess[i])
            sink++;
    }
    return sink;
}
//To compute how many hits that a guess has.(hit:correct number wrong position)
int computeHit(int secret[], int guess[], int test)
{
    int i,k,hit=0, temp[test];
    for(int j=0;j<test;j++)
        temp[j] = secret[j];
    for(i=0;i<test;i++)
        if(secret[i]==guess[i])
            {
                secret[i]=0;
                guess[i]=0;

            }
    for(i=0;i<test;i++)
    {
        for(k=0;k<test;k++)
        {
            if(secret[i]==0)
                break;
            if(secret[i]==guess[k] && i!=k)
            {
                hit++;
                guess[k]=0;
                break;
            }
        }
    }
    for(int j=0;j<test;j++)
        secret[j] = temp[j];
    return hit;
}
