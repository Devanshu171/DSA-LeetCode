class Solution {
public:
    string customSortString(string order, string ans) {
        map<char,int>mpp;
        for(auto it:ans)
            mpp[it]++;
       
        int k=0;
        for(int i=0;i<order.size();i++){
            while(mpp[order[i]]-->0) ans[k++]=order[i];
            
        }
          for(auto it:mpp){
              while(it.second-->0) ans[k++]=it.first;
          }  
        return ans;
    }
};