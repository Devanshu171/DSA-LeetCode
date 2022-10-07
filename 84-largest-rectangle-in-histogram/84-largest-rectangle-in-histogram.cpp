class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int>nsl;
        vector<int>nsr(n);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) nsl.push_back(st.top());
            else nsl.push_back(-1);
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) nsr[i]=st.top();
            else nsr[i]=(n);
            st.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int area=(nsr[i]-nsl[i]-1)*a[i];
            ans=max(area,ans);
        }
        return ans;
    }
};