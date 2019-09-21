#include <iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
	lli T,N;
	unordered_map<lli, lli> sA;
	cin>>T;
	while(T>0){
	    cin>>N;
    	lli A[N],B[N];
    	sA.clear();
    	for(lli i=0;i<N;i++){
    		cin>>A[i];
    		//cout<<i<<" ";
    		lli count=1;
    		//not found new entry
    		if(sA.find(A[i])==sA.end()){
    			sA.insert({A[i],count});
    		}
    		else{
    			sA[A[i]]+=1;
    			//cout<<sA[A[i]]<<"---"<<A[i]<<endl;
    		}
    	}
    	//cout<<"\n"<<T<<"======= sA size "<<sA.size()<<" N:"<<N<<endl;
    	for(lli i=0;i<N;i++){
    		cin>>B[i];
    	}
    	for(lli i=0;i<N;i++){
    		//not found
    		if(sA.find(B[i])==sA.end()){
    			cout<<0<<endl;
    			break;
    		}
    		else{
    			if(sA[B[i]]>1){
    				sA[B[i]]-=1;
    			}
    			else if(sA[B[i]]==1){
    				sA.erase(sA.find(B[i]));
    			}
    		}
    	}
    	if (sA.empty()){
    		cout<<1<<endl;
    	}
    	T=T-1;
	}
	return 0;
}