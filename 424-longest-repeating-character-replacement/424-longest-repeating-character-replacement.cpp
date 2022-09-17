class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int i=0,j=0,maxCnt=0,n=s.size();
        int ans=0;
        while(j<n){
            mpp[s[j]]++;
            maxCnt=max(maxCnt,mpp[s[j]]);
            while(j-i+1>maxCnt+k){
                mpp[s[i++]]--;
                for(auto it:mpp){
                    maxCnt=max(maxCnt,it.second);
                }
                
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};