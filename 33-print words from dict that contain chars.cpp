#include <bits/stdc++.h> 
using namespace std; 

bool isPresent(set<char> c, string a) 
{ 
	int count=0;
	for (unsigned int i = 0; 
		i < strlen(a.c_str()); i++) { 

		char ca = a[i]; 
		if (c.count(ca)) { 
			countval++; 
		} 
	} 

	return countval == strlen(a.c_str()); 
} 

int main() 
{ 
	set<string> dict;
	dict={"rat","mat","bat","chat","cat","tab","fat","batt"};
	set<char> c;
	c={'t','a','b','c'};

	for (auto it=dict.begin();it!=dict.end();it++) { 
		string a=*it; 
		if(isPresent(c,a)) 
			cout<<a<<endl; 
	} 
	return 0; 
} 
