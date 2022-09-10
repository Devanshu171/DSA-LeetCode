class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curPrdtLeft=1,maxPrdtLeft=INT_MIN;
        int curPrdtRight=1,maxPrdtRight=INT_MIN;
        
        
        for(int i=0;i<n;i++){
            curPrdtLeft*=nums[i];
            curPrdtRight*=nums[n-i-1];
            
              maxPrdtLeft=max(maxPrdtLeft,curPrdtLeft);
            maxPrdtRight=max(maxPrdtRight,curPrdtRight);
            
            if(curPrdtLeft==0) curPrdtLeft=1;
            if(curPrdtRight==0) curPrdtRight=1;
            
          
        }
        return max(maxPrdtLeft,maxPrdtRight);
    }
};