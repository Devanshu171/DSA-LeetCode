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
	    vector<int>lpss(s.size());
	    int i=1,j=0;
	    int ans=0,n=s.size();
	    lpss[0]=0;
	    while(i<n){
	        if(s[i]==s[j]){
	            lpss[i]=j+1;
	           // ans=max(ans,lpss[i]);
	            j++;
	            i++;
	        }else{
	            if(j!=0){
	                j=lpss[j-1];
	            }else{
	                lpss[i]=0;
	                i++;
	            }
	        }
	    }
	    return lpss.back();
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