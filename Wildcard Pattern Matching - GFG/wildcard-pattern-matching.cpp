// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

int solveMemo(int ind1,int ind2,string s,string p,vector<vector<int>>&dp){
        if(ind1==-1 && ind2==-1){
            return true;
        }
        
           
        if(ind1==-1 && ind2!=-1){
            while(ind2>=0 && p[ind2]=='*') ind2--;
            
            return ind2==-1;
        }
        if(ind1==-1 || ind2==-1) return false;
         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        else if(s[ind1]==p[ind2] || p[ind2]=='?') return dp[ind1][ind2]= solveMemo(ind1-1,ind2-1,s,p,dp);
       
       else if(p[ind2]=='*'){
            for(int i=ind1+1;i>=0;i--){
                if(solveMemo(i-1,ind2-1,s,p,dp)) return dp[ind1][ind2]=  true;
            }
        }
         return dp[ind1][ind2] =false;
    }
    


    int wildCard(string p,string s)
    {
         vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return solveMemo(s.size()-1,p.size()-1,s,p,dp);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends