class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=INT_MIN,c2=INT_MIN;
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==c1) count1++;
            else if(nums[i]==c2) count2++;
            else if(count1==0) count1=1,c1=nums[i];
            else if(count2==0) count2=1,c2=nums[i];
            else count1--,count2--;
        }
        count1=count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==c1)count1++;
            if(nums[i]==c2) count2++;
        }
        vector<int>ans;
        if(count1>n/3) ans.push_back(c1);
        if(count2>n/3) ans.push_back(c2);
        return ans;
        
    }
};