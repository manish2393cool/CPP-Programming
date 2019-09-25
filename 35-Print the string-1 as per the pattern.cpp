/*
Print the string-1 as per the pattern given
eg: for below output is "yzaaaddccbb"
*/
#include <iostream>
using namespace std;

int main() {
	string s="abcdabcdayz";
	string pat="yzadcb";
	int count[26]={0};
	for(int i=0;i<s.length();i++){
		count[int(s[i])-97]++;
	}
	string out="";
	for(int i=0;i<pat.length();i++){
		while(count[int(pat[i])-97]>0){
			out= out +pat[i];
			count[int(pat[i])-97]--;
		}
	}
	cout<<out<<endl;
	return 0;
}