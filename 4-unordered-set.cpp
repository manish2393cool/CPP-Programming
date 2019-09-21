#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<int> us;
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		us.insert(x);
	}
	cout<<us.size()<<endl;
	for(auto itr=us.begin();itr!=us.end();itr++){
		cout<<*itr<<" ";
	}
	return 0;
}