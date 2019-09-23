#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxsum(int arr[], int n){
	int max1=arr[0], max2=0, max_new;
	for(int i=1;i<n;i++){
		cout<<"Max1 :\t"<<max1<<" Max2 :\t"<<max2<<" Max_New :\t"<<max_new<<endl;
		max_new = max(max1,max2);
		max1 = max2 +arr[i];
		max2 = max_new;
				
	}
	cout<<"Max1 :\t"<<max1<<" Max2 :\t"<<max2<<" Max_New :\t"<<max_new<<endl;
	return max(max1,max2);
}

int main() {
	int arr[] = {95, 5, 10, 100, 10, 5,}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<maxsum(arr,n); 
	return 0;
}