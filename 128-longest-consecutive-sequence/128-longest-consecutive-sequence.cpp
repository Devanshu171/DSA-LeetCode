class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
         unordered_set<int>st;
      for(int i=0;i<n;i++){
          st.insert(arr[i]);
      }
      int ans=0;
      for(int i=0;i<n;i++){
          int k=arr[i];
          int curlen=0;
          if(st.count(k-1)) continue;
          else{
              while(st.count(k)){
            curlen++;
              k++;
              }
              
            ans=max(ans,curlen);  
          }
      }
      return ans;
    }
};