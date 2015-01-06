#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
long long int a,b=0,c,i,j,k,l;
vector<long long int>v;
for(i=0;i<=31;i++){
for(j=0;j<=31;j++){
for(k=0;k<=31;k++){
for(l=0;l<=31;l++){
a=pow(2,l)*pow(3,k)*pow(5,j)*pow(7,i);
if(a>0)
v.push_back(a);
}
}
}
}
sort(v.begin(),v.end());
while(cin>>a){
b++;
if(a==0)
break;

cout<<"The "<<a;
if(a%100==11 || a%100==12 || a%100==13)
cout<<"th ";
else if(((a%100)/10)==1)
cout<<"th ";
else if((a%10)==1)
cout<<"st ";
else if((a%10)==2)
cout<<"nd ";
else if((a%10)==3)
cout<<"rd ";
else
cout<<"th ";

cout<<"humble number is "<<v[a-1]<<"."<<endl;
}
return 0;
}
