class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur=1,prev=0,ans=0;
        for(int i=0;i<s.size();i++){
            while(i<s.size()-1 && s[i]==s[i+1]){
                i++;
                cur++;
            } 
            ans+=min(prev,cur);
            prev=cur;
            cur=1;
            
        }
        return ans;
    }
};