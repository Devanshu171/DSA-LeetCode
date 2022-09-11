class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size(),ans=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
           
            int r=time[i]%60;
            if(r==0) ans+=mpp[r];
            else if(mpp.find(60-r)!=mpp.end()){
                ans+=mpp[60-r];
            }
            mpp[r]++;
        }
    
        return ans; 
    }
};