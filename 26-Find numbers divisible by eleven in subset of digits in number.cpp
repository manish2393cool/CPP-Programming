#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ifdiv(int x){
	if(x%11==0) return true;
	return false;
}

vector<int> isdivisible(int inp, int len){
	vector<int> res;
	vector<int> subsets,dig;
	int temp=inp;
	string s;
	while(temp>0){
		int d=temp%10;
		dig.emplace(dig.begin(), d);
		temp=temp/10;
	}
	for(auto i:dig){
		cout<<i<<" ";
	}cout<<endl;
	for(int i=0;i<dig.size();i++){
		string temp="";
		for(int j=i;j<dig.size();j++){
			temp+=to_string(dig[j]);
			int check=stoi(temp);
			if(ifdiv(check)) res.push_back(check);
		}
	}
	
	return res;
}


int main() {
	// your code goes here
	int k=121341;
	int len=4;
	vector<int> v;
	v = isdivisible(k,len);
	for(auto i:v){
		cout<<i<<",";
	}
	return 0;
}