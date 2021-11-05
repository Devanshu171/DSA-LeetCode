class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>vec(n);
        stack<int>st;
        int k=n-1;
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && temp[st.top()]<=temp[i]) st.pop();
            
            if(!st.empty()) vec[k--]=st.top()-i;
            else vec[k--]=0;
            
            st.push(i);
        }
        return vec;
    }
};