/*
Expand the string according to the given conditions
Given a string str of the type “3(ab)4(cd)”, 
the task is to expand it to “abababcdcdcdcd”
where integers are from the range [1, 9].
*/
#include <iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

void exps(string s){
	vector<string> v;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			string t="";
			int j=1;
			while(s[i+j]!=')'){
				t = t+s[i+j];
				j++;
			}
			i=i+j;
			v.push_back(t);
		}
		else{
			string t(1,s[i]);
			v.push_back(t);
		}
	}
	// for(auto i:v){
	// 	cout<<i<<",";
	// }
	string ans="";
	for(int i=0;i<v.size();i+=2){
		int t=stoi(v[i]);
		while(t>0){
			ans= ans+ v[i+1];
			t--;
		}
	}
	cout<< ans;
	return;
}

int main() {
	// your code goes here
	string s= "2(kl)3(ap)";
	exps(s);
	return 0;
}