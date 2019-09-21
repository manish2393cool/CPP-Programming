#include <iostream>
#include<bits/stdc++.h>
#define lli long long int
using namespace std;

int main() {
	int T,N;
	set<int> s={1,2,3,4};
	vector<int> op;
	cin>>T;
	int flag=-1;
	while(T>0){
	    cin>>N;
    	int A[N];
    	for(int i=0; i<N; i++)
    		cin>>A[i];
    	for(int i=0; i<N; i++){
    		cout<<A[i]<<" ";
    		int temp=A[i];
    		flag=-1;
    		while(temp>0){
    			int mod=temp%10;
    			//not found
    			if(s.find(mod)==s.end()){
    				flag=1;
    				break;
    			}
    			temp=temp/10;
    		}
    		if(flag==-1){
    			//digits other than 1,2,3,dont add to output
    			op.push_back(A[i]);
    		}
    	}
    	cout<<endl;
    	cout<<"output is :";
    	if(op.size()>0){
	    	for(auto itr=op.begin();itr!=op.end();itr++){
	    		cout<<*itr<<" ";
	    	}
    	}
    	else{
    		cout<<-1;
    	}
    	cout<<endl;
    	op.clear();
    	T=T-1;
	}
	return 0;
}