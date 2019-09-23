// typedef pair<int, int> Pair;
// vector<vector<int> > Solution::fourSum(vector<int> &A, int total) {
//     vector<vector<int>> ans;
//     unordered_map<int, vector<Pair>> map;
//     set<vector<int>> s;
//     int n=A.size();
//     sort(A.begin(),A.end());
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             int sum = total - (A[i]+A[j]);
//             if (map.find(sum) != map.end()){
//                 for (auto pair : map.find(sum)->second){
//                     int x = pair.first;
//                     int y = pair.second;
//                     if ((x!=i && x!=j) && (y!=i && y!=j))
//                     {
//                         //cout<<"Quadruplet("<<A[i]<<","<<A[j]<<","<<A[x]<<","<<A[y]<< ")";
//                         //cout<<"\n";
//                         vector<int> temp;
//                         temp.push_back(A[i]);
//                         temp.push_back(A[j]);
//                         temp.push_back(A[x]);
//                         temp.push_back(A[y]);
//                         sort(temp.begin(),temp.end());
//                         //ans.push_back(temp);
//                         s.insert(temp);
//                         break;
//                     }
//                 }
//             }
//             map[A[i]+A[j]].push_back({i,j});
//         }
//     }
//     //cout<<ans.size();
    
//     for(auto it=s.begin();it!=s.end();it++){
    
//         ans.push_back(*it);
//     }
    
//     return ans;
// }
vector<vector<int> > Solution::fourSum(vector<int> &nums, int target) {
    vector<vector<int>> total;
        int n = nums.size();
        if(n<4)  return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target) left++;
                    else if(sum>target) right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                }
            }
        }
        return total;
}

