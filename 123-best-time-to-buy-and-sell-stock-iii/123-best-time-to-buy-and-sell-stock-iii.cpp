class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>profit(n,0);
        int buy=INT_MAX;
        int mp=0;
        for(int i=0;i<n;i++){
            if(buy>prices[i]){
                buy=prices[i];
            }else if(mp<prices[i]-buy){
                mp=prices[i]-buy;
            }
            profit[i]=mp;
            // cout<<mp<<" ";
        }
        int sell=0;
        mp=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            sell=max(sell,prices[i]);
            mp=max(0,sell-prices[i]);
            profit[i]=max(profit[i],mp+profit[i]);
            ans=max(ans,profit[i]);
        }
          
        return ans;
    }
};