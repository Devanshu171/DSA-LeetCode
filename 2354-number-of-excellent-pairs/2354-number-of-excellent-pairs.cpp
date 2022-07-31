class Solution {
public:
 
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<int>arr;
        long long ans=0;
     int n=nums.size();
          sort(nums.begin(),nums.end());
        arr.push_back(nums[0]);
   
      
        
        for(int i=1;i<n;i++){
            while(nums[i]==nums[i-1]){
                i++;
            }
            arr.push_back(nums[i]);
        }
        
        for(int i=0;i<arr.size();i++){
            int x=arr[i];
            arr[i]=__builtin_popcount(x);
           
            
        }
        n=arr.size();
          sort(arr.begin(),arr.end());
        
       for(int i=0;i<n;i++){
           ans+=n-(lower_bound(arr.begin(),arr.end(),k-arr[i])-arr.begin());
       }
        return ans;
    }
};