// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:	
#define mod 1000000007
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    long long int count[s.size()];
        count[0]=2;
        unordered_map<char,long>mpp;
        
        mpp[s[0]]=1;
        
        for(int i=1;i<s.size();i++){
            int rep=0;
            if(mpp.find(s[i])!=mpp.end()){
                rep=mpp[s[i]];
            }
            
            count[i]=((count[i-1]%mod)*2)%mod;
            count[i]-=rep%mod;
        if(count[i]<0) count[i]+=mod;
                mpp[s[i]]=count[i-1]%mod;
                
            
        }
        
        return count[s.size()-1]%mod;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends