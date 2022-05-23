class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prdt=1;
        int i=0,j=0,ans=0;
        int n=nums.size();
        
        while(j<n){
            prdt*=nums[j];
            while(i<n && prdt>=k){
                prdt/=nums[i++];
            }
            if(prdt<k) ans+=j-i+1;
            j++;
        }
        return ans;
    }
};