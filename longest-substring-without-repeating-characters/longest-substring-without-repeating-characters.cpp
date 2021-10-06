class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
unordered_set<char>st;
        int i=0,j=0,maxlen=0;
        int n=s.size();
        while(j<n)
        {
            
            if(st.find(s[j])==st.end())
                {
                    st.insert(s[j]);
                    maxlen=max(maxlen,j-i+1);
                    j++;
                }
                
                else
                {
                    while(st.find(s[j])!=st.end())
                    {
                        st.erase(s[i]);
                        i++;
                    }
                    
                }
                
        }
        return maxlen;
    }
};