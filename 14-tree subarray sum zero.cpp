#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    if (subArrayExists(arr, n))
			cout << "Yes";
		else
			cout << "No";
		cout<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//Complete this function
bool subArrayExists(int arr[], int n)
{
    //Your code here
    int presum=0,flag=0;
    map<int,int> m;
    for(int i=0;i<n;i++){
    	presum=presum+arr[i];
    	//not found add to map
        if(m.find(presum)==m.end()){
        	m.insert({presum,i});
        }
        else{
        	auto itr_pos=m.find(presum);
        	cout<<"From "<<(itr_pos->second)<<" to "<<i<<" position."<<endl;
        	flag=1;
        	break;
        }
    }
    if(flag){
    	for(auto itr=m.begin();itr!=m.end();itr++){
        	cout<<itr->first<<"-"<<itr->second<<" || ";
    	}
    	return true;
    }
    m.clear();
    return false;
}