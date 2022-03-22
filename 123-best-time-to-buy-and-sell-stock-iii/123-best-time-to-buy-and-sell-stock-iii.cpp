class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit[n];
        int buy=INT_MAX;
      int  cp=INT_MIN;
        int mxi=cp;
        
        for(int i=0;i<n;i++){
            buy=min(buy,prices[i]);
            cp=max(cp,prices[i]-buy);
            mxi=max(mxi,cp);
            profit[i]=mxi;
        }
        int sell=INT_MIN;
        cp=INT_MIN;
        mxi=cp;
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            sell=max(sell,prices[i]);
            cp=max(cp,sell-prices[i]);
            mxi=max(cp,mxi);
            profit[i]+=mxi;
            ans=max(ans,profit[i]);
        }
        return ans;
    }
};