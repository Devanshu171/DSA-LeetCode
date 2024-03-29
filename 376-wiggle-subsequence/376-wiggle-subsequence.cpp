class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
         
        int n=nums.size();
        if(n==1) return 1;
        int ans=1;
        int prevDiff=0;
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            if(diff>0 && prevDiff<=0 || diff<0 && prevDiff>=0){
                ans++;
                prevDiff=diff;
            }
        }
        return ans;
    }
};