class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int ans=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=sum%k;
            if(r<0) r+=k;
            if(mpp.find(r)!=mpp.end()){
                ans+=mpp[r]; 
            }
            mpp[r]++;
        }
        return ans;
    }
};