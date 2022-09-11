class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n=nums.size();
         k=n-k;
        
        int i=0,j=0,sum=0,tsum=0,ans=INT_MAX;
        while(j<n){
            tsum+=nums[j];
            sum+=nums[j];
             cout<<j-i+1<<" "<<k<<endl;
            if(j-i+1==k){
               
                ans=min(ans,sum);
                sum-=nums[i++];
            }
            j++;
        }
        return tsum-(ans==INT_MAX?0:ans);
    }
};