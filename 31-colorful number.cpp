/*
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
*/

int Solution::colorful(int A) {
    map<int,int> m;
    vector<int> v;
    while(A>0){
        v.push_back(A%10);
        A=A/10;
    }
    int prod=1;
    for(int i=0;i<v.size();i++){
        for(int l=1;l<=v.size();l++){
            prod=1;
            if(i<l){
                for(int j=i;j<l ;j++){
                    prod*=v[j];
                    
                }
                // cout<<i<<","<<l-1<<endl;
            if(m.find(prod)!=m.end()){
                //found
                m[prod]+=1;
                return 0;
            }
            else
                m.insert({prod,1});
            }
        }
    }
    
    // cout<<endl;
    // for(auto itr=m.begin();itr!=m.end();itr++){
    //     cout<<itr->first<<":"<<itr->second<<endl;
    // }
    // cout<<endl;
    
    return 1;
}
