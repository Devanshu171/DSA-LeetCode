class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int tsum=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]%2==0)
            tsum+=nums[i];
        }
        for(int i=0;i<queries.size();i++){
            int ind=queries[i][1];
            int val=queries[i][0];
            if((nums[ind] & 1) && ((nums[ind]+val) & 1)) nums[ind]+=val;
            else if((nums[ind] & 1) && !((nums[ind]+val) & 1)){
                nums[ind]+=val;
                    tsum+=nums[ind];
            }else if(!(nums[ind] & 1) && !((nums[ind]+val) & 1)){
                nums[ind]+=val;
                tsum+=val;
            }else if(!(nums[ind] & 1) && ((nums[ind]+val) & 1)){
                tsum-=nums[ind];
                nums[ind]+=val;
            }
           
            ans.push_back(tsum);
        }
        return ans;
    }
};