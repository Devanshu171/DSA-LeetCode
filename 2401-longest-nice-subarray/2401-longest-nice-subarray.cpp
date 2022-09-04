class Solution {
public:
    bool getSet(int n,vector<int>&bits,bool add){
        for(int i=0;i<32;i++){
                if(add) bits[i]+=(n>>i & 1);
                else bits[i]-=(n>>i &  1);
        }
        
        for(int i=0;i<32;i++){
            if(bits[i]>1) return false;
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
    
            int n=nums.size();
        int ans=0;
        vector<int>bits(32,0);
        int i=0;
        for(int j=0;j<n;j++){
            int valid=getSet(nums[j],bits,true);
            while(i<j && !valid){
                valid=getSet(nums[i++],bits,false);
            }
            ans=max(ans,j-i+1);
        }
        return ans;
       
    }
};