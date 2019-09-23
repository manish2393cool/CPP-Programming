//interviewbit solution

vector<int> Solution::twoSum(const vector<int> &A, int sum) {
    vector<int> ans;
    map<int,int> m;
    //insert first element in map as (A[0],index)
    m[A[0]]=1;

    // for(auto i:A){
    //     cout<<i<<" ";
    // }cout<<endl;
    
    for(int i=1;i<A.size();i++){
        if(m.find(sum-A[i])==m.end()){
            m.insert({A[i],i+1});
            //cout<<A[i]<<":"<<i+1<<" ";
        }
        else{
            //cout<<m[sum-A[i]]<<","<<i+1<<" ";
            ans.push_back(m[sum-A[i]]);
            ans.push_back(i+1);
            break;
        }
    }
    return ans;
}