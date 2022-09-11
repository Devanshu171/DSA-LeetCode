class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dis=INT_MAX;
        int ans;
        for(int i=0;i<nums.size()-2;i++){
            int s=i+1,e=nums.size()-1;
            
            while(s<e){
                int sum=nums[i]+nums[s]+nums[e];
                if(sum==target) return sum;
        
                if(abs(target-sum)<abs(target-ans)){
                    ans=sum;
                }
                if(sum<target){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return ans;
    }
};