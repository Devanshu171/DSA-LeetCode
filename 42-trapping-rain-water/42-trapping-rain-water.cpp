class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        int maxl=0,maxr=0;
        for(int i=0;i<n;i++){
            maxl=max(maxl,height[i]);
            maxr=max(maxr,height[n-i-1]);
            left[i]=maxl;
            right[n-i-1]=maxr;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(ans,min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};