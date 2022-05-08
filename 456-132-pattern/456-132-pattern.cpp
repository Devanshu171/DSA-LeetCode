class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        int one=INT_MIN;
      for(int i=nums.size()-1;i>=0;i--){
          if(nums[i]<one) return true;
          while(!st.empty() && st.top()<nums[i]){
              one=st.top();
              st.pop();
          }
          st.push(nums[i]);
      }
        
        return false;
    }
};