#include <iostream>
#include <unordered_map> 
using namespace std;

int main() {
	unordered_map<int,int> um;
	array<int,15> arr= {1,2,4,1,3, 5,3,2,6,4, 4,4,2,3,4};
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
		if(um.find(arr[i])==um.end()){
			um[arr[i]]=1;
		}
		else{
			int count=um[arr[i]];
			um[arr[i]]=count+1;
		}
	}
	cout<<endl;
	int max=0,ele=0;
	for (auto x : um){ 
		cout << x.first << "--" << x.second << endl;
		if(x.second>=max){
			max=x.second;
			ele=x.first;}
	}
	cout<<ele<<" appeared "<< max<<" times."<<endl;
	return 0;
}