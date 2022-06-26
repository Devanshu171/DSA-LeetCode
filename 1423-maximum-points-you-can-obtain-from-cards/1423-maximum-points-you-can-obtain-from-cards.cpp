class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        
        // need to find subarray of size n-k with min sum so that rest has max sum i.e score
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++) sum+=arr[i];
        if(k==n) return sum;
        k=n-k;
        int subsum=0;
        int i=0,j=0;
        int ans=INT_MAX;
        while(j<n){
            subsum+=arr[j];
            if(j-i+1==k){
                ans=min(ans,subsum);
                subsum-=arr[i];
                i++;
            }
            j++;
        }
        
        return sum-ans;
    }
};