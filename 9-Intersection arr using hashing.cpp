#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T,N;
	cin>>T;
	while(T>0){
	    cin>>N;
    	int arr[N];
    	for(int i=0;i<N;i++){
    		cin>>arr[i];
    	}
    // 	for(int i=0;i<N;i++){
    // 		cout<<arr[i]<<" ";
    // 	}
    // 	cout<<endl;
    	set<int> s;
    	int min=-1;
    	for(int i=N-1;i>=0;i--){
    		//if already there
    		if(s.find(arr[i])!=s.end()){
    			min=i;
    		}
    		else{
    			s.insert(arr[i]);
    		}
    	}
    	if(min!=-1)
    	    cout<<min+1<<endl;
    	else
    	    cout<<-1<<endl;
    	s.clear();
    	T=T-1;
	}
	return 0;
}