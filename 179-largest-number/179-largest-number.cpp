class Solution {
public:

    string largestNumber(vector<int>& arr) {
        vector<string>nums;
        for(auto it:arr){
            nums.push_back(to_string(it));
        }
        sort(begin(nums),end(nums),[](string &a,string &b){
            return a+b>b+a;
        });
        string ans="";
        int i=0;
        while(i<nums.size()-1 && nums[i]=="0") i++;
        for(;i<nums.size();i++){
        
            ans+=(nums[i]);
        }

    
        return ans;
    }
};