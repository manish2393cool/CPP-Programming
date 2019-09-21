#include <iostream>
using namespace std;

void printsub(string str,string curr="",int index=0){
	if(index==str.length()){
		cout<<curr<<" ";
		// vstr.push_back(curr);
		return;
	}
	printsub(str,curr,index+1);
	printsub(str,curr+str[index],index+1);
}

int main() {
	string str;
	cin>>str;
	string curr="";
	int index=0;
	printsub(str,curr="",index=0);
	// sort(vstr);
	// for(int i=0;i<vstr.size();i++){
	// 	cout<<v[i]
	// }
	return 0;
}