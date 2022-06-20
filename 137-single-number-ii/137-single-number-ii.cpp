class Solution {
public:
    int singleNumber(vector<int>& nums) {

              long ans = 0;

        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]>>i & 1) count++;
                
            }
           if(count%3!=0){
               ans+=pow(2,i);
           }
        }
        
        return ans;
    
        
    }
};