#include <iostream>

using namespace std;

int main ()
{
   longint i, j, result;

   while(cin >> i >> j)
   {
	result = 0; 
if(i<j)
result=j-i;
else
	result = i-j;

cout<<result<<endl;
   }
return 0;
}     