class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        int maxl=height[0],maxr=height[n-1];
        for(int i=1;i<n;i++){
            maxl=max(maxl,height[i]);
            maxr=max(maxr,height[n-i-1]);
            left[i]=maxl;
            right[n-i-1]=maxr;
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++){
            cout<<min(left[i],right[i])-height[i]<<" "<<i<<endl;
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};