#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int numhead, numsol,solcount,headcount, total;
    int head[20000], soldier[20000];
    while(cin>>numhead>>numsol && numhead && numsol){
        for(int i=0;i<numhead;i++)
            cin>>head[i];
        for(int i=0;i<numsol;i++)
            cin>>soldier[i];
        if(numhead>numsol)
            cout<<"Loowater is doomed!"<<endl;
        else{
            sort(head,head+numhead);
            sort(soldier,soldier+numsol);
            total = headcount = solcount = 0;
            while(headcount<numhead && solcount<numsol){
                while(head[headcount]>soldier[solcount]){
                    solcount++;
                    if(solcount == numsol)
                        break;
                }
                if(solcount==numsol)
                    break;
                total+=soldier[solcount];
                solcount++;
                headcount++;

            }
            if(headcount<numhead)
                cout<<"Loowater is doomed!"<<endl;
            else if(headcount == numhead)
                cout<<total<<endl;

        }

    }
    return 0;
}
