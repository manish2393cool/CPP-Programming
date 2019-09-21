#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<stdio.h>
using namespace std;

class Solution{
	public:
string minWindow(string s, string t) {
        int s_count[256] = {0};
        int t_count[256] = {0};
        if(s.length()<t.length()){
            return "";
        }
        for(int i=0;i<t.length();i++){
            t_count[t[i]]++;
        }
        int f=0,f_index=-1,minl=INT_MAX;
        int count=0;
        int windowl=0;
        for(int i=0;i<s.length();i++){
            s_count[s[i]]++;
            if(t_count[s[i]]!=0 && s_count[s[i]]<=t_count[s[i]] ){
                count++;
            }
            
            if(count==t.length()){
                while((s_count[s[f]] > t_count[s[f]])|| t_count[s[f]]==0){
                    if(s_count[s[f]] > t_count[s[f]]){
                        s_count[s[f]]--;
                    }
                    f++;
                }
                windowl=i-f+1;
                if (minl>windowl){
                    minl = windowl;
                    f_index = f;
                }
                cout<<"equal "<<count<<"::"<<windowl<<"::"<<endl;
            }
            cout<<"debug"<<minl<<":"<<windowl<<":"<<count<<": i="<<i<<endl;
        }
        if(f_index==-1)
        {
           cout<<"No";
           return "";
        }
        return s.substr(f_index,minl);
}
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);
        
        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}

// int main(){
// 	string res,s,t;
// 	cin>>s;
// 	cin>>t;
// 	res = minWindow(s, t);
// 	cout<<res<<endl;
// 	return 0;
// }