#include <iostream>
#include <algorithm>
using namespace std;
int count = 0;
int func(int n,int a,int b,int c){
	if(n==0)
		return 0;
	if(n<0)
		return -1;
	int res = max( func(n-a,a,b,c), max( func(n-b,a,b,c), func(n-c,a,b,c)) );
	if(res==-1)
		return -1;
	return res+1;
}
int main() {
	// your code goes here
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	cout<<func(n,a,b,c);
	return 0;
}