class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        nums.resize(n*2);
        int j=0;
        for(int i=n;i<nums.size();i++)
            nums[i]=nums[j++];
        
        vector<int>vec(nums.size());
        int k=nums.size()-1;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i]) st.pop();
            if(!st.empty()) vec[k--]=st.top();
            else vec[k--]=-1;
            st.push(nums[i]);
        }
        
        vec.resize(n);
        return vec;
    }
};