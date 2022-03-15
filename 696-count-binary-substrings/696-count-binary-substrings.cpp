class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur_cons=1,prev_cons=0;
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                ans+=min(prev_cons,cur_cons);
                prev_cons=cur_cons;
                cur_cons=1;
            }else{
                cur_cons++;
            }
        }
          ans+=min(prev_cons,cur_cons);
        return ans;
        
    }
};