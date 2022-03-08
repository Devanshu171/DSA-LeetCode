class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        int last=0;
            
        for(auto it:mpp){
           st.insert(it.second);
        }
        
        return st.size()==mpp.size();
    }
};