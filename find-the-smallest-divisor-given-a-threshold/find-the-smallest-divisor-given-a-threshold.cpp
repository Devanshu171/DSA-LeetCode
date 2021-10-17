class Solution {
public:
    
    bool isvalid(vector<int>&a,int n,int k,int div)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(a[i]+div-1)/div;
            if(sum>k)
                return false;
        }
        return true;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxs=0;
        int res=-1;
        for(int i=0;i<n;i++)
        {
            maxs=max(maxs,nums[i]);
        
        }
        
        int start=1;
        int end=maxs;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isvalid(nums,n,threshold,mid))
            {
                res=mid;
                end=mid-1;
                
            }
            
            else
                start=mid+1;
        }
        
        return res;
        
        
    }
};