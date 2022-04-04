// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    vector<int>ans(s.size());
	    ans[0]=0;
	    int j=0,i=1;
	    while(i<s.size()){
	        if(s[i]==s[j]){
	            ans[i]=j+1;
	            i++;j++;
	        }else{
	            if(j!=0){
	                j=ans[j-1];
	                }else{
	                    ans[i]=0;
	                    i++;
	                }
	        }
	    }
	    return ans[s.size()-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends