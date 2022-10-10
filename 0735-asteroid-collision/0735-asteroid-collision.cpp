class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(arr[i]);

            }else{
                if(arr[i]<0){
                    if(st.top()<0){
                        st.push(arr[i]);
                    }
                    else if(st.top()>0 &&  st.top()<abs(arr[i])){
                        
                   
                    while(!st.empty() && st.top()>0 &&  st.top()<abs(arr[i])){
                        st.pop();
                    }
                         if(st.empty() || abs(arr[i])>st.top()){
                         st.push(arr[i]);
                    }
                        if(st.top()==abs(arr[i])){
                        st.pop();
                    }
                }
                   else if(st.top()==abs(arr[i])){
                        st.pop();
                    }
                    
                }else{
                    st.push(arr[i]);
                }
                
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};