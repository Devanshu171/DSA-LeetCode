class Solution {
public:
    bool validateStackSequences(vector<int>& A, vector<int>& B) {
         stack<int>st;
        
        int j=0;
        for(int i=0;i<A.size();i++){
            st.push(A[i]);
            while(!st.empty() && B[j]==st.top()){
                j++;
                st.pop();
            }
        }
        return st.empty();
        
    }
};