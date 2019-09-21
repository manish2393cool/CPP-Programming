#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T,N,M;
	cin>>T;
	while(T>0){
	    cin>>N>>M;
    	int A[N],B[M];
    	set<int> inter,sA,sB;
    	for(int i=0;i<N;i++){
    		cin>>A[i];
    		sA.insert(A[i]);
    	}
    	for(int i=0;i<M;i++){
    		cin>>B[i];
    		sB.insert(B[i]);
    	}
    // 	for(int i=0;i<N;i++){
    // 		cout<<arr[i]<<" ";
    // 	}
    // 	cout<<endl;
    	// for(int i=0;i<M;i++){
    	for(auto itr=sA.begin();itr!=sA.end();itr++){
    		//if found in array A
    		if(sB.find(*itr)!=sB.end()){
    			inter.insert(*itr);
    		}
    	}
    	// cout<<"-inter size -"<<inter.size()<<endl;
    	// cout<<"-sA size -"<<sA.size()<<endl;
    	// cout<<sizeof(B)/sizeof(1);
    	cout<<inter.size()<<endl;
    	sA.clear();
    	inter.clear();
    	T=T-1;
	}
	return 0;
}