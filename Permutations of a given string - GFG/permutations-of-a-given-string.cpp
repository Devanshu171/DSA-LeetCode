// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:
	void helper(int i,string s,vector<string>&ans){
	    if(i==s.size()){
	        ans.push_back(s);
	        return;
	    }
	    for(int ind=i;ind<s.size();ind++){
	        swap(s[i],s[ind]);
	        helper(i+1,s,ans);
	        swap(s[i],s[ind]);
	    }
	}
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string>ans;
		    helper(0,s,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends