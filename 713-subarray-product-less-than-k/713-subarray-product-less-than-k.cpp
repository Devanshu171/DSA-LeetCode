class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prdt=1;
        int i=0,j=0,ans=0;
        
        while(j<nums.size()){
            prdt*=nums[j];
            while(i<nums.size() && prdt>=k){
                prdt/=nums[i++];
            }
            if(prdt<k) ans+=j-i+1;
            j++;
        }
        return ans;
    }
};