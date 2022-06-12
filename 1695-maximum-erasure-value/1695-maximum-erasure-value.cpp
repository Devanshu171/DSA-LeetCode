class Solution {
public:
    int maximumUniqueSubarray(vector<int>& s) {
            int i=0,j=0,maxsum=0;
    int n=s.size();
    unordered_map<int,int>mpp;
    if(n==0) return 0;
        int maxlen=1;
        int ans=1;
    while(j<n)
    {
        mpp[s[j]]++;
        maxsum+=s[j];
        
        if(mpp[s[j]]>1)
        {
            while(mpp[s[j]]>1)
            {
                mpp[s[i]]--;
                maxsum-=s[i];
                i++;

            }
        }
        ans=max(ans,maxsum);
        j++;
    }
    
    return ans;

    }
};