class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>vec(n);
        stack<pair<int,int>>st;
        int k=n-1;
        for(int i=n-1;i>=0;i--){

            while(!st.empty() && st.top().first<=temp[i]) st.pop();
            
            if(!st.empty()) vec[k--]=st.top().second-i;
            else vec[k--]=0;
            
            st.push(make_pair(temp[i],i));
        }
        return vec;
    }
};