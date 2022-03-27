class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
      int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){           
            int sum3=target-nums[i];
            for(int j=i+1;j<n-2;j++){    
                int sum2=sum3-nums[j];
                int s=j+1,e=n-1;
                
                while(s<e){
                    
                   int sum=nums[s]+nums[e];
                    
                    if(sum>sum2) e--;
                    else if(sum<sum2) s++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        while(s<e && nums[s]==nums[s+1]) s++;
                        while(s<e && nums[e]==nums[e-1]) e--;
                        s++;e--;
                      
                    }
                }
              
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
            
        }
        return ans;
    }
};