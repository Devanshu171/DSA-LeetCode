// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int minChar(string s){
int n=s.size();
   string str=s;
  s.push_back('#');
   reverse(str.begin(),str.end());
  s=s+str;

           vector<int>lps(s.size());
           lps[0]=0;
           int i=1,j=0;
          while(i<s.size()){
              if(s[i]==s[j]){
                  lps[i]=j+1;
                  i++;j++;
              }else{
                  if(j!=0){
                      j=lps[j-1];
                  }else{
                      lps[i]=0;
                      i++;
                  }
              }
          }
    
    return n-lps.back();
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends