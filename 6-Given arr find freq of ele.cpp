#include <iostream>
#include <unordered_map> 
using namespace std;

int main() {
	unordered_map<int,int> um;
	array<int,10> arr= {1,2,4,1,3,5,3,2,6,1};
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
	for (auto x : um) 
      cout << x.first << " " << x.second << endl; 
	return 0;
}