

class Solution {
public:

    
    void solve(int ind,string s,string temp,vector<string>&ans){
           if(ind==s.size()){
               ans.push_back(temp);
               return;
           }
           
             if(isdigit(s[ind])){
                   temp+=s[ind];
                   solve(ind+1,s,temp,ans);
               } 
                else{
            temp+=tolower(s[ind]);
           solve(ind+1,s,temp,ans);
           temp.pop_back();
           temp+=toupper(s[ind]);           
        solve(ind+1,s,temp,ans);
                }
        
    }

    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(0,s,"",ans);
        return ans;
        
    }
};