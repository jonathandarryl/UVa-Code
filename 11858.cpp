#include<iostream>
using namespace std;
void mergesort(int [], int, int);
void merge(int [], int, int, int);
long long swapz;
int main(void){
    int length, train[1000001];
    int test, temp;
    bool is_sorted;
    while(cin>>length){
        swapz = 0;
        for(int j=0;j<length;j++)
            cin>>train[j];
        mergesort(train, 0, length-1);
        cout<<swapz<<endl;
    }
    return 0;
}

void mergesort(int a[], int i, int j) {

	if (i < j) {
		int mid = (i+j)/2;
		mergesort(a, i, mid);
		mergesort(a, mid+1, j);
		merge(a,i,mid,j);
	}
}


void merge(int a[], int i, int mid, int j) {
	int temp[j-i+1];
	int left = i, right = mid+1, it = 0;

	while (left<=mid && right<=j) {
		if (a[left] <= a[right]){
			temp[it++] = a[left++];
		}
		else{
		    swapz+=mid-left+1;
			temp[it++] = a[right++];

		}
	}

	while (left<=mid){
	    temp[it++] = a[left++];

	}
	while (right<=j)
        temp[it++] = a[right++];
    for (int k = 0;k < j-i+1; k++)
		a[i+k] = temp[k];
}


