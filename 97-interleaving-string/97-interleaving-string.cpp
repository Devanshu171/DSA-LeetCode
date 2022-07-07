class Solution {
public:
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
    bool isInterleave(string s1, string s2, string s3) {
        // return solveRec(s1.size()-1,s2.size()-1,s3.size()-1,s1,s2,s3);
        vector<vector<vector<int>>>dp(s1.size(),vector<vector<int>>(s2.size(),vector<int>(s3.size(),-1)));
        return solveMemo(s1.size()-1,s2.size()-1,s3.size()-1,s1,s2,s3,dp);
    }
};