// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int solveRec(int ind1,int ind2,int ind3,string s1,string s2,string s3){
        if(ind3==-1 && (ind1!=-1 || ind2!=-1)) return false;
            if(ind3==-1) return true;
            if(ind1==-1 && ind2==-1 ) return false;

            if(ind1>=0 && ind2>=0 && s1[ind1]==s3[ind3] && s2[ind2]==s3[ind3]){
              return solveRec(ind1-1,ind2,ind3-1,s1,s2,s3) || solveRec(ind1,ind2-1,ind3-1,s1,s2,s3);
            }
            else if(ind1>=0 && s1[ind1]==s3[ind3]) return solveRec(ind1-1,ind2,ind3-1,s1,s2,s3);
            else if(ind2>=0 && s2[ind2]==s3[ind3]) return solveRec(ind1,ind2-1,ind3-1,s1,s2,s3);
            
            else return false;
            
 }
    int solveMemo(int ind1,int ind2,int ind3,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
            if(ind3==-1 && (ind1!=-1 || ind2!=-1)) return false;
            if(ind3==-1) return true;
            if(ind1==-1 && ind2==-1 ) return false;
              if( ind1>=0 && ind2>=0 && ind3>=0 &&dp[ind1][ind2][ind3]!=-1) return dp[ind1][ind2][ind3];
            if(ind1>=0 && ind2>=0 && s1[ind1]==s3[ind3] && s2[ind2]==s3[ind3]){
              return dp[ind1][ind2][ind3]= solveMemo(ind1-1,ind2,ind3-1,s1,s2,s3,dp) || solveMemo(ind1,ind2-1,ind3-1,s1,s2,s3,dp);
            }
            else if(ind1>=0 && s1[ind1]==s3[ind3]) return  solveMemo(ind1-1,ind2,ind3-1,s1,s2,s3,dp);
            else if(ind2>=0 && s2[ind2]==s3[ind3]) return  solveMemo(ind1,ind2-1,ind3-1,s1,s2,s3,dp);
            
            else return  false;
            
 }
     int solveTabu(string s1,string s2,string s3){
      int n=s1.size(),m=s2.size(),k=s3.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));
        dp[0][0][0]=1;

        for(int ind1=1;ind1<=n;ind1++){
          for(int ind2=1;ind2<=m;ind2++){
            for(int ind3=1;ind3<=k;ind3++){
              if( s1[ind1-1]==s3[ind3-1] && s2[ind2-1]==s3[ind3-1]){
             dp[ind1][ind2][ind3]=   dp[ind1-1][ind2][ind3-1] ||  dp[ind1][ind2-1][ind3-1];
            }
            else if(s1[ind1-1]==s3[ind3-1]) dp[ind1][ind2][ind3]=   dp[ind1-1][ind2][ind3-1];
            else if(s2[ind2-1]==s3[ind3-1]) dp[ind1][ind2][ind3]=   dp[ind1][ind2-1][ind3-1];
            
            else  dp[ind1][ind2][ind3]= false;
            }
          }
        }
        return dp[n][m][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        // return solveRec(s1.size()-1,s2.size()-1,s3.size()-1,s1,s2,s3);
        vector<vector<vector<int>>>dp(s1.size(),vector<vector<int>>(s2.size(),vector<int>(s3.size(),-1)));
        return solveMemo(s1.size()-1,s2.size()-1,s3.size()-1,s1,s2,s3,dp);
        //  return solveTabu(s1,s2,s3);
    }
   

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends