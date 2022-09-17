class Solution {
public:
    bool check(string s){
        
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                ans+=check(s.substr(i,j-i+1));
            }
        }
        return ans;
    }
};