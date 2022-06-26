// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int getTabu(string s1,string s2,vector<vector<int>>&dp){
	    int n=s1.size();
	    int m=s2.size();
	    
	    for(int ind1=1;ind1<=n;ind1++){
	        for(int ind2=1;ind2<=m;ind2++){
	            if(s1[ind1-1]==s2[ind2-1]){
	                dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
	            }else{
	                dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
	            }
	        }
	    }
	    
	    return dp[n][m];
	}
	void solveRec(int ind1,int ind2,int len,string temp,string s1,string s2,vector<string>&ans,unordered_set<string>&st){
	   
	   if(len==0){
	       if(st.count(temp)==0){
	           st.insert(temp);
	        ans.push_back(temp);
	       }
	        return;
	   }
	   if(ind1==s1.size()|| ind2==s2.size()) return;
	   
	        for(int i=ind1;i<s1.size();i++){
	            for(int j=ind2;j<s2.size();j++){
	                if(s1[i]==s2[j]){
	                    temp.push_back(s1[i]);
	                    solveRec(i+1,j+1,len-1,temp,s1,s2,ans,st);
	                    temp.pop_back();
	                }
	            }
	        }
	}
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    // Code here
		       int n=s1.size();
	             int m=s2.size();
		    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
		   int lcs= getTabu(s1,s2,dp);
		    vector<string>ans;
		    unordered_set<string>st;
		    solveRec(0,0,lcs,"",s1,s2,ans,st);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}

  // } Driver Code Ends