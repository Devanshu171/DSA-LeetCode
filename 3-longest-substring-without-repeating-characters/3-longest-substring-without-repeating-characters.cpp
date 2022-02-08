class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mpp;
        int i=0,j=0,n=s.size(),mx=0;
        while(j<n){
            mpp[s[j]]++;
            if(mpp.size()==j-i+1){
                mx=max(j-i+1,mx);
                j++;
            }
            else{
                while(mpp.size()<j-i+1){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0) mpp.erase(s[i]);
                    i++;
                }
                
                 if(mpp.size()==j-1+1) mx=max(j-i+1,mx);
                
                j++;
            
            }
            
        }
        return mx;
    }
};