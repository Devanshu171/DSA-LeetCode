class Solution {
public:
    int maxArea(vector<int>& height) {
     int n=height.size();
        int ans=-1;
        int s=0,e=n-1;
        while(s<e){
            int area=(e-s)*min(height[s],height[e]);
            ans=max(ans,area);
            if(height[s]<=height[e]) s++;
            else e--;
        }
        return ans;
    }
};