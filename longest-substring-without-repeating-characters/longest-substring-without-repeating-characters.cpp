class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0,j=0,ans=0;
        // if(s.size()==0)
        //     return 0;
        
        while(j<s.size()){
            if(st.find(s[j])==st.end()){
                ans=max(ans,j-i+1);
                st.insert(s[j]);
                j++;
            }
            else if(st.find(s[j])!=st.end()){
                while(st.find(s[j])!=st.end()){
                    st.erase(s[i]);
                    i++;
                }
                
            }
        }
        return ans;
    }
};