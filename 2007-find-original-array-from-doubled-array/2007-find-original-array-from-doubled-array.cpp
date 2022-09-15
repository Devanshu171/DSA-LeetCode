class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int>mpp;
        if(changed.size()%2!=0) return {};
        for(auto it:changed) mpp[it]++;
        vector<int>ans;
        for(auto it:mpp){

                  while(mpp[it.first]>0 && mpp[it.first*2]>0){
                       ans.push_back(it.first);
                mpp[it.first]--;
                mpp[it.first*2]--;
            }
        }
        
        
        for(auto it:mpp){
              // cout<<it.first<<" "<<it.second<<endl;
            if(it.second!=0){
              
                return{};
            } 
        }
        return ans;
    }
};